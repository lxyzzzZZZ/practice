//void chushou::OnBnClickedButton1()//出售
//{
//	// TODO: 在此添加控件通知处理程序代码
//
//	CString str1, str2, str3, str4;
//	GetDlgItem(IDC_EDIT1)->GetWindowText(str1);//种类
//	GetDlgItem(IDC_EDIT2)->GetWindowText(str2);//名称
//	GetDlgItem(IDC_EDIT5)->GetWindowText(str3); //价格
//	GetDlgItem(IDC_EDIT6)->GetWindowText(str4);//库存
//
//	string zhonglei, mingcheng, jiage, kucun;
//
//	zhonglei = CW2A(str1.GetString());
//	mingcheng = CW2A(str2.GetString());
//	jiage = CW2A(str3.GetString());
//	kucun = CW2A(str4.GetString());
//	string xiaoliang = "0";
//
//	ofstream a1("产品资料.txt", ios::app);
//
//	a1 << root << endl;
//	a1 << zhonglei << endl;
//	a1 << mingcheng << endl;
//	a1 << jiage << endl;
//	a1 << kucun << endl;
//	a1 << xiaoliang << endl;
//
//	a1.close();
//
//
//	//更新种类
//	ifstream a3("产品种类.txt");
//	string zhonglei_T;
//	int flag = 0;
//	while (a3 >> zhonglei_T)
//	{
//		if (zhonglei == zhonglei_T)
//		{
//			flag = 1;
//			break;
//		}
//	}
//	a3.close();
//
//
//	if (flag == 0)
//	{
//		ofstream a2("产品种类.txt", ios::app);
//		a2 << zhonglei << endl;
//		a2.close();
//	}
//
//	CString str6;
//	str6 = "售卖成功！！！";
//	SetDlgItemText(IDC_EDIT8, str6);
//}
//
//
//
//void shangdian::OnBnClickedButton2()//商店
//{
//	// TODO: 在此添加控件通知处理程序代码
//
//	CString mingcheng;//产品名称
//	GetDlgItem(IDC_EDIT2)->GetWindowText(mingcheng);
//	string mingcheng_T;
//	mingcheng_T = CW2A(mingcheng.GetString());
//
//	ifstream file("产品资料.txt");
//	ifstream file1("产品资料.txt");
//	string a, b;
//	CString a1;
//	while (file >> a)
//	{
//		file1 >> b;
//		file >> a;
//		file >> a;
//		if (a == mingcheng_T)
//		{
//			file1 >> b;
//			a1 = b.c_str();
//			SetDlgItemText(IDC_EDIT3, a1);
//			file1 >> b;
//			a1 = b.c_str();
//			SetDlgItemText(IDC_EDIT4, a1);
//			file1 >> b;
//			a1 = b.c_str();
//			SetDlgItemText(IDC_EDIT6, a1);
//			file1 >> b;
//			a1 = b.c_str();
//			SetDlgItemText(IDC_EDIT7, a1);
//			file1 >> b;
//			a1 = b.c_str();
//			SetDlgItemText(IDC_EDIT8, a1);
//		}
//		else
//		{
//			file >> a;
//			file >> a;
//			file >> a;
//			file1 >> b;
//			file1 >> b;
//			file1 >> b;
//			file1 >> b;
//			file1 >> b;
//		}
//	}
//	file.close();
//	file1.close();
//}
//
//
//void gouwuche::OnBnClickedButton1()//购物车
//	// TODO: 在此添加控件通知处理程序代码
//	ifstream file("订单.txt");
//string name;
//CString name_jm;
//string a;
//while (file >> name)
//{
//	if (name == root)
//	{
//		file >> name;
//		file >> name;
//		file >> name;//名称
//
//		a = a + name;
//		a = a + ',';
//		//name_jm = name.c_str();
//		//SetDlgItemText(IDC_EDIT1, name_jm);
//		file >> name;
//		file >> name;
//	}
//	else
//	{
//		file >> name;
//		file >> name;
//		file >> name;
//		file >> name;
//		file >> name;
//	}
//}
//file.close();
//a.pop_back();
//name_jm = a.c_str();
//SetDlgItemText(IDC_EDIT1, name_jm);
//
//}