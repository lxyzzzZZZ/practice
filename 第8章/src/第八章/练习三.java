package �ڰ���;
import java.awt.event.*;
import javax.swing.*;
public class ��ϰ�� extends JFrame{
	private JPopupMenu popupMenu;
	public ��ϰ��() {
		popupMenu = new JPopupMenu();
		JMenuItem refreshItem = new JMenuItem("refresh");
		JMenuItem createItem = new JMenuItem("create");
		JMenuItem exitItem = new JMenuItem("exit");
		exitItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});
		popupMenu.add(refreshItem);
		popupMenu.add(createItem);
		popupMenu.addSeparator();
		popupMenu.add(exitItem);
		this.addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
				if(e.getButton() == e.BUTTON3) {
					popupMenu.show(e.getComponent(), e.getX(), e.getY());
				}
			}
		});
		this.setSize(300, 300);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
}
	public static void main(String[] args) {
		new ��ϰ�� ();
	}
}













//1��	������Example20�̳���JFrame�����ڴ���һ������ʽ�˵���
//2��	����JPopupMenu�˵����󣬽��������JFrame���ڵĶ�����
//3��	���������˵��refreshItem��createItem��exitItem��
//4��	ΪexitItem�˵�������¼����������������ʱ���˳�����
//5��ΪJFrame�������clicked����¼������������������������Ҽ�����ʾJPopupMenu�˵���
