package 第八章;
import java.awt.*;
public class 练习二 {
	public static void main(String[] args) {
		Frame f = new Frame("GridLayout");
		f.setLayout(new GridLayout(4, 3));
		f.setSize(300, 300);
		f.setLocation(400, 300);
		for (int i = 0; i < 12; i++) {
			Button btn = new Button("btn" + (i+1));
			f.add(btn);
		}
		f.setVisible(true);
	}
}












//1）	编写类Example03，创建一个名为"网格布局"的窗体。
//2）	设置该窗体为4*3的网格。
//3） 循环添加12个按钮到GridLayout中, 