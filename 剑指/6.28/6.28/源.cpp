//void chushou::OnBnClickedButton1()//����
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//
//	CString str1, str2, str3, str4;
//	GetDlgItem(IDC_EDIT1)->GetWindowText(str1);//����
//	GetDlgItem(IDC_EDIT2)->GetWindowText(str2);//����
//	GetDlgItem(IDC_EDIT5)->GetWindowText(str3); //�۸�
//	GetDlgItem(IDC_EDIT6)->GetWindowText(str4);//���
//
//	string zhonglei, mingcheng, jiage, kucun;
//
//	zhonglei = CW2A(str1.GetString());
//	mingcheng = CW2A(str2.GetString());
//	jiage = CW2A(str3.GetString());
//	kucun = CW2A(str4.GetString());
//	string xiaoliang = "0";
//
//	ofstream a1("��Ʒ����.txt", ios::app);
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
//	//��������
//	ifstream a3("��Ʒ����.txt");
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
//		ofstream a2("��Ʒ����.txt", ios::app);
//		a2 << zhonglei << endl;
//		a2.close();
//	}
//
//	CString str6;
//	str6 = "�����ɹ�������";
//	SetDlgItemText(IDC_EDIT8, str6);
//}
//
//
//
//void shangdian::OnBnClickedButton2()//�̵�
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//
//	CString mingcheng;//��Ʒ����
//	GetDlgItem(IDC_EDIT2)->GetWindowText(mingcheng);
//	string mingcheng_T;
//	mingcheng_T = CW2A(mingcheng.GetString());
//
//	ifstream file("��Ʒ����.txt");
//	ifstream file1("��Ʒ����.txt");
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
//void gouwuche::OnBnClickedButton1()//���ﳵ
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	ifstream file("����.txt");
//string name;
//CString name_jm;
//string a;
//while (file >> name)
//{
//	if (name == root)
//	{
//		file >> name;
//		file >> name;
//		file >> name;//����
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