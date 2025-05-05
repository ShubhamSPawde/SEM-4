import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Calculator extends JFrame {
    private JTextField textField = new JTextField();
    
    public Calculator() {
        setTitle("Calculator");
        setSize(300, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        textField.setHorizontalAlignment(JTextField.LEFT);
        add(textField, BorderLayout.NORTH);
        
        JPanel panel = new JPanel(new GridLayout(4, 4));
        String[] buttons = {"7", "8", "9", "/", "4", "5", "6", "*", "1", "2", "3", "-", "0", "+", "Enter"};
        for (String text : buttons) {
            panel.add(new JButton(text));
        }
    //     JButton button2 = new JButton("Enter");
    //    button.setBounds(300, 100, 150, 50);

        add(panel, BorderLayout.CENTER);
        setVisible(true);
    }
    
    public static void main(String[] args) {
        new Calculator();
    }
}
