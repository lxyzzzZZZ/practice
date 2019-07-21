#include "httplib.h"
#include <fstream>
#include <iostream>
#include <ostream>
#include <boost/filesystem.hpp>
#define SERVER_ROOT_DIR "www"
#define SERVER_IP "0.0.0.0"
#define SERVER_PORT 9999
#define SERVER_BACKUP_DIR SERVER_ROOT_DIR"/list/"
namespace bf = boost::filesystem;
class CloudServer
{
private:
	httplib::Server srv;
public:
	CloudServer()
	{
		bf::path base_path(SERVER_ROOT_DIR);
		if (!bf::exists(base_path))
		{
			bf::create_directory(base_path);
		}
		bf::path list_path(SERVER_BACKUP_DIR);
		if (!bf::exists(list_path))
		{
			bf::create_directory(list_path);
		}
	}
	bool Start()
	{
		srv.set_base_dir(SERVER_ROOT_DIR);
		srv.Get("/(list)(/){0,1}){0,1}", GetFileList);
		srv.Get("/list/(.*)", GetFileData);
		srv.Put("/list/(.*)", PutFileData);
		srv.listen(SERVER_IP, SERVER_PORT);
		return true;
	}
private:
	static void PutFileData(const httplib::Request &req, httplib::Response &rsp)
	{
		//std::string real = SERVER_ROOT_DIR + req.path;
		//std::ofstream file(real, std::ios::binary|std::ios::trunc);
		//if (!file.is_open())
		//{
		//  std::cerr << "open file " << real << "error" << std::endl;
		//  rsp.status = 500;
		//  return;
		// }
		if (!req.has_header("Range"))
		{
			rsp.status = 400;
			return;
		}
		std::string range = req.get_header_value("Range");
		int64_t range_start;
		if (RangeParse(range, range_start) == false)
		{
			rsp.status = 400;
			return;
		}
		std::string real = SERVER_ROOT_DIR + req.path;
		std::ofstream file(real, std::ios::binary | std::ios::trunc);
		if (!file.is_open())
		{
			std::cerr << "open file " << real << " error" << std::endl;
			rsp.status = 500;
			return;
		}
		file.seekp(range_start, std::ios::beg);
		file.write(&req.body[0], req.body.size());
		if (!file.good())
		{
			std::cerr << "file write body error" << std::endl;
			rsp.status = 500;
			return;
		}
		file.close();
		return;
	}
	static bool RangeParse(std::string &range, int64_t &start)
	{
		size_t pos1 = range.find("=");
		size_t pos2 = range.find("=");
		if (pos1 == std::string::npos || pos2 == std::string::npos)
		{
			std::cerr << "range:[" << range << "] format error" << std::endl;
			return false;
		}
		std::stringstream rs;
		rs << range.substr(pos1 + 1, pos2 - pos1 - 1);
		rs >> start;
		return true;
	}
	static void GetFileList(const httplib::Request &req, httplib::Response &rsp)
	{
		bf::path list(SERVER_BACKUP_DIR);
		bf::directory_iterator item_begin(list);
		bf::directory_iterator item_end;
		std::string body;
		body = "<html><body><ol><hr />";
		for (; item_begin != item_end; ++item_begin)
		{
			if (bf::is_directory(item_begin->status()))
			{
				continue;
			}
			std::string file = item_begin->path().filename().string();
			std::string uri = "/list/" + file;
			body += "<h4><li>";
			body += "a href='";
			body += uri;
			body += "'>";
			body += file;
			body += "</a>";
			body += "</li></h4>";
		}
		body += "<hr /></ol></body></html>";
		rsp.set_content(&body[0], "text/html");
		return;
	}
	static void GetFileData(const httplib::Request &req, httplib::Response &rsp)
	{
		std::string file = SERVER_BACKUP_DIR + req.path;
		if (!bf::exists(file))
		{
			std::cerr << "file " << file << "is not exists" << std::endl;
			rsp.status = 404;
			return;
		}
		std::ifstream ifile(file, std::ios::binary);
		if (!ifile.is_open())
		{
			std::cerr << "open file " << file << "error" << std::endl;
			rsp.status = 500;
			return;
		}
		std::string body;
		int64_t fsize = bf::file_size(file);
		body.resize(fsize);
		ifile.read(&body[0], fsize);
		if (!ifile.good())
		{
			std::cerr << "read file " << file << "body error" << std::endl;
			rsp.status = 500;
			return;
		}
		rsp.set_content(body, "text/plain");
	}
	// static void BackupFile(const httplib::Request &req, httplib::Response &rsp)
	// {

	//var }
};


int main()
{
	CloudServer srv;
	srv.Start();
	return 0;
}
