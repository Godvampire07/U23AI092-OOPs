package postmid;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class jdbc {
    private static final String DB_URL = "jdbc:mysql://localhost:3306/userdb";
    private static final String DB_USER = "root"; // Replace with your DB username
    private static final String DB_PASSWORD = "Mihir@123"; // Replace with your DB password

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new jdbc().createGUI());
    }

    public void createGUI() {
        JFrame frame = new JFrame("Login and Registration");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);

        JTabbedPane tabbedPane = new JTabbedPane();

        // Registration Panel
        JPanel registerPanel = new JPanel(new GridLayout(4, 2));
        JTextField regUsernameField = new JTextField();
        JTextField regEmailField = new JTextField();
        JPasswordField regPasswordField = new JPasswordField();
        JButton registerButton = new JButton("Register");

        registerPanel.add(new JLabel("Username:"));
        registerPanel.add(regUsernameField);
        registerPanel.add(new JLabel("Email:"));
        registerPanel.add(regEmailField);
        registerPanel.add(new JLabel("Password:"));
        registerPanel.add(regPasswordField);
        registerPanel.add(new JLabel());
        registerPanel.add(registerButton);

        registerButton.addActionListener(e -> {
            String username = regUsernameField.getText();
            String email = regEmailField.getText();
            String password = new String(regPasswordField.getPassword());

            if (registerUser(username, password, email)) {
                JOptionPane.showMessageDialog(frame, "Registration Successful!");
            } else {
                JOptionPane.showMessageDialog(frame, "Registration Failed! Try again.");
            }
        });

        // Login Panel
        JPanel loginPanel = new JPanel(new GridLayout(3, 2));
        JTextField loginUsernameField = new JTextField();
        JPasswordField loginPasswordField = new JPasswordField();
        JButton loginButton = new JButton("Login");

        loginPanel.add(new JLabel("Username:"));
        loginPanel.add(loginUsernameField);
        loginPanel.add(new JLabel("Password:"));
        loginPanel.add(loginPasswordField);
        loginPanel.add(new JLabel());
        loginPanel.add(loginButton);

        loginButton.addActionListener(e -> {
            String username = loginUsernameField.getText();
            String password = new String(loginPasswordField.getPassword());

            if (authenticateUser(username, password)) {
                JOptionPane.showMessageDialog(frame, "Login Successful!");
            } else {
                JOptionPane.showMessageDialog(frame, "Invalid Credentials.");
            }
        });

        tabbedPane.add("Register", registerPanel);
        tabbedPane.add("Login", loginPanel);

        frame.add(tabbedPane);
        frame.setVisible(true);
    }

    private boolean registerUser(String username, String password, String email) {
        try (Connection conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD)) {
            String query = "INSERT INTO users (username, password, email) VALUES (?, ?, ?)";
            try (PreparedStatement stmt = conn.prepareStatement(query)) {
                stmt.setString(1, username);
                stmt.setString(2, password);
                stmt.setString(3, email);
                stmt.executeUpdate();
                return true;
            }
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
    }

    private boolean authenticateUser(String username, String password) {
        try (Connection conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD)) {
            String query = "SELECT * FROM users WHERE username = ? AND password = ?";
            try (PreparedStatement stmt = conn.prepareStatement(query)) {
                stmt.setString(1, username);
                stmt.setString(2, password);
                ResultSet rs = stmt.executeQuery();
                return rs.next();
            }
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
    }
}
