package �ڰ���;
import java.awt.*;
import java.awt.event.*;
public class ��ϰһ {
	public static void main(String[] args) {
		final Frame f = new Frame("Flowlayout");
		f.setLayout(new FlowLayout(FlowLayout.LEFT,30,50));
		f.setSize(220, 300);
		f.setLocation(300, 200);
		//f.add(new Button("1"));
		f.setVisible(true);
		Button btn = new Button("����");
		f.add(btn);
		btn.addMouseListener(new MouseAdapter(){
			public void mouseClicked(MouseEvent e) {
				f.add(new Button("��"));
				f.setVisible(true);
			}
		});
	}
	
}


//1��	��д��Example01������һ����Ϊ����ʽ���֡��Ĵ��塣
//2��	���ô����еĲ��ֹ�����ΪFlowLayout��
//3��	����1����ť����Ϊ��ť��ӵ���¼���ÿ���һ�ΰ�ť���������µİ�ť��