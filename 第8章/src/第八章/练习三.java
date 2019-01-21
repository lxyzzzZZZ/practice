package 第八章;
import java.awt.event.*;
import javax.swing.*;
public class 练习三 extends JFrame{
	private JPopupMenu popupMenu;
	public 练习三() {
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
		new 练习三 ();
	}
}













//1）	定义类Example20继承自JFrame，用于创建一个弹出式菜单。
//2）	创建JPopupMenu菜单对象，将其放置在JFrame窗口的顶部。
//3）	创建三个菜单项：refreshItem、createItem、exitItem。
//4）	为exitItem菜单项添加事件监听器，当点击它时会退出程序。
//5）为JFrame窗口添加clicked鼠标事件，监听器如果点击的是鼠标的右键，显示JPopupMenu菜单。
