package 第八章;
import java.awt.*;
import java.awt.event.*;
public class 练习一 {
	public static void main(String[] args) {
		final Frame f = new Frame("Flowlayout");
		f.setLayout(new FlowLayout(FlowLayout.LEFT,30,50));
		f.setSize(220, 300);
		f.setLocation(300, 200);
		//f.add(new Button("1"));
		f.setVisible(true);
		Button btn = new Button("创建");
		f.add(btn);
		btn.addMouseListener(new MouseAdapter(){
			public void mouseClicked(MouseEvent e) {
				f.add(new Button("新"));
				f.setVisible(true);
			}
		});
	}
	
}


//1）	编写类Example01，创建一个名为“流式布局”的窗体。
//2）	设置窗体中的布局管理器为FlowLayout。
//3）	创建1个按钮，并为按钮添加点击事件，每点击一次按钮就再生成新的按钮。