package �ڰ���;
import java.awt.*;
public class ��ϰ�� {
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












//1��	��д��Example03������һ����Ϊ"���񲼾�"�Ĵ��塣
//2��	���øô���Ϊ4*3������
//3�� ѭ�����12����ť��GridLayout��, 