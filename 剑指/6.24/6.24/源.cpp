///********************************************************
//��������:void display2()
//��������:��ʾ�����¶���ֵ
//����˵��:
//********************************************************/
//void display2()
//{
//	num++;
//
//	lcd1602_write_character(0, 1, "Limiting value");			 //�̶���ʾ
//	lcd1602_write_character(0, 2, "Up:");
//	lcd1602_write_character(7, 2, "Dowm:");
//	if (num % 2 == 0)	//ż������ʾ�������β���ʾ�������ͻ�����˸Ч�����������������ǰ���õ����ĸ�ֵ
//	{
//		LCD_disp_char(3, 2, ASCII[Temperature_up % 1000 / 100]);	 //��ʾ �¶�����ֵ
//		LCD_disp_char(4, 2, ASCII[Temperature_up % 100 / 10]);
//		LCD_disp_char(5, 2, ASCII[Temperature_up % 10]);
//
//		LCD_disp_char(12, 2, ASCII[Temperature_down % 1000 / 100]);//��ʾ �¶�����ֵ
//		LCD_disp_char(13, 2, ASCII[Temperature_down % 100 / 10]);
//		LCD_disp_char(14, 2, ASCII[Temperature_down % 10]);
//	}
//	else			//�����β���ʾ
//	{
//		if (set_f == 1)
//			lcd1602_write_character(3, 2, "   ");	//��ʾ�ո�
//		if (set_f == 2)
//			lcd1602_write_character(12, 2, "   ");
//	}
//}
///********************************************************
//��������:void scan(void)
//��������:������⴦��
//����˵��:
//********************************************************/
//void scan(void)
//{
//	//���ü�����֧������
//	if (key_set == 0)	  //��������
//	{
//		delayms(7);	    //��ʱ����
//		if (key_set == 0)  //�ٴ�ȷ�ϰ��°���
//		{
//			ledr = 1;	    //�رձ�����
//			ledy = 1;	    //�رձ�����
//			ledg = 1;	    //�رձ�����
//			buzz = 1;	    //�رշ�����
//
//			set_f++;    //���ñ���+1
//			if (set_f == 1)//��������ʱ���������Ļ
//			{
//				LCD_write_command(0x01);//�����Ļ��ʾ
//				delay_n40us(100);		//��ʱ�ȴ�ȫ��������
//			}
//			if (set_f == 3)//���������ɣ��˳�����
//			{
//				set_f = 0;//�������ñ���
//				EEPROM_delete(0x2002);				  //��������
//				EEPROM_write(0x2002, Temperature_up);  //д�롾�¶�����ֵ�����ݱ���
//
//				EEPROM_delete(0x2202);				  //��������
//				EEPROM_write(0x2202, Temperature_down);//д�롾�¶�����ֵ�����ݱ���
//
//				LCD_write_command(0x01);//�����Ļ��ʾ
//				delay_n40us(100);		//��ʱ�ȴ�ȫ��������
//			}
//		}
//		while (!key_set);                //�ȴ������ɿ�
//	}
//
//	//��ֵ����֧������
//	if (key_jia == 0 && set_f != 0)
//	{
//		delayms(7);
//		if (key_jia == 0)
//		{
//			if (set_f == 1)               //���� �¶�����ֵ
//			{
//				if (Temperature_up < 125) //���ֵ������125��
//					Temperature_up++;  //�¶�����ֵ+1��			
//			}
//
//			if (set_f == 2)               //���� �¶�����ֵ
//			{
//				if (Temperature_down < 125 && Temperature_down + 1 < Temperature_up)//���ֵ������125�棬�������޲��ɳ�������
//					Temperature_down++;//�¶�����ֵ+1��		 
//			}
//		}
//	}
//
//	//��ֵ����֧������
//	if (key_jian == 0 && set_f != 0)
//	{
//		delayms(7);
//		if (key_jian == 0)
//		{
//			if (set_f == 1)               //���� �¶�����ֵ
//			{
//				if (Temperature_up != 0 && Temperature_up > Temperature_down + 1)//��Сֵ������0�棬�������޵ñ����޴�
//					Temperature_up--;  //�¶�����ֵ-1��
//			}
//
//			if (set_f == 2)               //���� �¶�����ֵ
//			{
//				if (Temperature_down != 0)//��Сֵ������0��
//					Temperature_down--;//�¶�����ֵ-1��
//			}
//		}
//	}
//}