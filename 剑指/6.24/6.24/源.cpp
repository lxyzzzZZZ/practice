///********************************************************
//函数名称:void display2()
//函数作用:显示设置温度限值
//参数说明:
//********************************************************/
//void display2()
//{
//	num++;
//
//	lcd1602_write_character(0, 1, "Limiting value");			 //固定显示
//	lcd1602_write_character(0, 2, "Up:");
//	lcd1602_write_character(7, 2, "Dowm:");
//	if (num % 2 == 0)	//偶数次显示，奇数次不显示。这样就会有闪烁效果，可以清楚看到当前设置的是哪个值
//	{
//		LCD_disp_char(3, 2, ASCII[Temperature_up % 1000 / 100]);	 //显示 温度上限值
//		LCD_disp_char(4, 2, ASCII[Temperature_up % 100 / 10]);
//		LCD_disp_char(5, 2, ASCII[Temperature_up % 10]);
//
//		LCD_disp_char(12, 2, ASCII[Temperature_down % 1000 / 100]);//显示 温度下限值
//		LCD_disp_char(13, 2, ASCII[Temperature_down % 100 / 10]);
//		LCD_disp_char(14, 2, ASCII[Temperature_down % 10]);
//	}
//	else			//奇数次不显示
//	{
//		if (set_f == 1)
//			lcd1602_write_character(3, 2, "   ");	//显示空格
//		if (set_f == 2)
//			lcd1602_write_character(12, 2, "   ");
//	}
//}
///********************************************************
//函数名称:void scan(void)
//函数作用:按键检测处理
//参数说明:
//********************************************************/
//void scan(void)
//{
//	//设置键，不支持连按
//	if (key_set == 0)	  //按键按下
//	{
//		delayms(7);	    //延时消抖
//		if (key_set == 0)  //再次确认按下按键
//		{
//			ledr = 1;	    //关闭报警灯
//			ledy = 1;	    //关闭报警灯
//			ledg = 1;	    //关闭报警灯
//			buzz = 1;	    //关闭蜂鸣器
//
//			set_f++;    //设置变量+1
//			if (set_f == 1)//进入设置时，先清除屏幕
//			{
//				LCD_write_command(0x01);//清除屏幕显示
//				delay_n40us(100);		//延时等待全部清除完毕
//			}
//			if (set_f == 3)//如果设置完成，退出设置
//			{
//				set_f = 0;//重置设置变量
//				EEPROM_delete(0x2002);				  //擦除扇区
//				EEPROM_write(0x2002, Temperature_up);  //写入【温度上限值】数据保存
//
//				EEPROM_delete(0x2202);				  //擦除扇区
//				EEPROM_write(0x2202, Temperature_down);//写入【温度下限值】数据保存
//
//				LCD_write_command(0x01);//清除屏幕显示
//				delay_n40us(100);		//延时等待全部清除完毕
//			}
//		}
//		while (!key_set);                //等待按键松开
//	}
//
//	//加值键，支持连按
//	if (key_jia == 0 && set_f != 0)
//	{
//		delayms(7);
//		if (key_jia == 0)
//		{
//			if (set_f == 1)               //设置 温度上限值
//			{
//				if (Temperature_up < 125) //最大值可设置125℃
//					Temperature_up++;  //温度上限值+1℃			
//			}
//
//			if (set_f == 2)               //设置 温度下限值
//			{
//				if (Temperature_down < 125 && Temperature_down + 1 < Temperature_up)//最大值可设置125℃，并且下限不可超过上限
//					Temperature_down++;//温度下限值+1℃		 
//			}
//		}
//	}
//
//	//减值键，支持连按
//	if (key_jian == 0 && set_f != 0)
//	{
//		delayms(7);
//		if (key_jian == 0)
//		{
//			if (set_f == 1)               //设置 温度上限值
//			{
//				if (Temperature_up != 0 && Temperature_up > Temperature_down + 1)//最小值可设置0℃，并且上限得比下限大
//					Temperature_up--;  //温度上限值-1℃
//			}
//
//			if (set_f == 2)               //设置 温度下限值
//			{
//				if (Temperature_down != 0)//最小值可设置0℃
//					Temperature_down--;//温度下限值-1℃
//			}
//		}
//	}
//}