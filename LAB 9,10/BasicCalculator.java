package postmid;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class BasicCalculator extends JFrame implements ActionListener, FocusListener, KeyListener {
    private JTextField display;
    private JButton[] numberButtons = new JButton[10];
    private JButton addButton, subButton, mulButton, divButton, clrButton, eqlButton;
    private JPanel panel;
 
    // Variables to store values for operations
    private double num1 = 0, num2 = 0, result = 0;
    private char operator;

    public BasicCalculator() {
        setTitle("Basic Calculator");
        setSize(400, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Initialize display and set properties
        display = new JTextField();	
        display.setFont(new Font("Arial", Font.BOLD, 24));
        display.setEditable(false);
        display.addFocusListener(this); // Adding focus listener
        display.addKeyListener(this); // Adding key listener

        // Create buttons for numbers and operations
        for (int i = 0; i < 10; i++) {
            numberButtons[i] = new JButton(String.valueOf(i));
            numberButtons[i].addActionListener(this); // Adding action listener
            numberButtons[i].addKeyListener(this); // Adding key listener
        }
        
        addButton = new JButton("+");
        subButton = new JButton("-");
        mulButton = new JButton("*");
        divButton = new JButton("/");
        clrButton = new JButton("C");
        eqlButton = new JButton("=");

        // Add action listeners to operation buttons
        addButton.addActionListener(this);
        subButton.addActionListener(this);
        mulButton.addActionListener(this);
        divButton.addActionListener(this);
        clrButton.addActionListener(this);
        eqlButton.addActionListener(this);

        // Add key listeners to operation buttons
        addButton.addKeyListener(this);
        subButton.addKeyListener(this);
        mulButton.addKeyListener(this);
        divButton.addKeyListener(this);
        clrButton.addKeyListener(this);
        eqlButton.addKeyListener(this);

        // Panel for the buttons
        panel = new JPanel();
        panel.setLayout(new GridLayout(4, 4, 10, 10));

        // Add buttons to the panel
        panel.add(numberButtons[1]);
        panel.add(numberButtons[2]);
        panel.add(numberButtons[3]);
        panel.add(addButton);

        panel.add(numberButtons[4]);
        panel.add(numberButtons[5]);
        panel.add(numberButtons[6]);
        panel.add(subButton);

        panel.add(numberButtons[7]);
        panel.add(numberButtons[8]);
        panel.add(numberButtons[9]);
        panel.add(mulButton);

        panel.add(clrButton);
        panel.add(numberButtons[0]);
        panel.add(eqlButton);
        panel.add(divButton);

        // Add components to the frame
        add(display, BorderLayout.NORTH);
        add(panel, BorderLayout.CENTER);

        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        // Check for number buttons
        for (int i = 0; i < 10; i++) {
            if (e.getSource() == numberButtons[i]) {
                display.setText(display.getText() + i);
            }
        }

        // Check for operator buttons
        if (e.getSource() == addButton) {
            num1 = Double.parseDouble(display.getText());
            operator = '+';
            display.setText("");
        } else if (e.getSource() == subButton) {
            num1 = Double.parseDouble(display.getText());
            operator = '-';
            display.setText("");
        } else if (e.getSource() == mulButton) {
            num1 = Double.parseDouble(display.getText());
            operator = '*';
            display.setText("");
        } else if (e.getSource() == divButton) {
            num1 = Double.parseDouble(display.getText());
            operator = '/';
            display.setText("");
        } else if (e.getSource() == clrButton) {
            display.setText("");
            num1 = num2 = result = 0;
        } else if (e.getSource() == eqlButton) {
            num2 = Double.parseDouble(display.getText());
            switch (operator) {
                case '+': result = num1 + num2; break;
                case '-': result = num1 - num2; break;
                case '*': result = num1 * num2; break;
                case '/': result = (num2 != 0) ? num1 / num2 : 0; break;
            }
            display.setText(String.valueOf(result));
            num1 = result;
        }
    }

    @Override
    public void focusGained(FocusEvent e) {
        if (e.getSource() == display) {
            display.setBackground(Color.LIGHT_GRAY); // Highlight on focus
        }
    }

    @Override
    public void focusLost(FocusEvent e) {
        if (e.getSource() == display) {
            display.setBackground(Color.WHITE); // Reset color on focus loss
        }
    }

    @Override
    public void keyTyped(KeyEvent e) {
        char keyChar = e.getKeyChar();

        // Allow numbers and basic operators via keyboard input
        if (Character.isDigit(keyChar)) {
            display.setText(display.getText() + keyChar);
        } else if (keyChar == '+' || keyChar == '-' || keyChar == '*' || keyChar == '/') {
            num1 = Double.parseDouble(display.getText());
            operator = keyChar;
            display.setText("");
        } else if (keyChar == '=') {
            num2 = Double.parseDouble(display.getText());
            switch (operator) {
                case '+': result = num1 + num2; break;
                case '-': result = num1 - num2; break;
                case '*': result = num1 * num2; break;
                case '/': result = (num2 != 0) ? num1 / num2 : 0; break;
            }
            display.setText(String.valueOf(result));
            num1 = result;
        } else if (keyChar == 'c' || keyChar == 'C') {
            display.setText("");
            num1 = num2 = result = 0;
        }
    }

    @Override
    public void keyPressed(KeyEvent e) {
        // Not used in this example
    }

    @Override
    public void keyReleased(KeyEvent e) {
        // Not used in this example
    }

    public static void main(String[] args) {
        new BasicCalculator();
    }
}
