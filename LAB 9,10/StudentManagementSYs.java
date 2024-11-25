package postmid;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

public class StudentManagementSYs {

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new StudentManagementSystem().createAndShowGUI());
    }
}

class StudentManagementSystem {
    private JFrame frame;
    private JTextField idField, nameField, ageField, departmentField;
    private JComboBox<String> genderBox;
    private JTable table;
    private DefaultTableModel tableModel;

    public void createAndShowGUI() {
        frame = new JFrame("Student Management System");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 600);
        frame.setLayout(new BorderLayout());

        // Input Form Panel
        JPanel formPanel = new JPanel(new GridLayout(6, 2, 10, 10));
        formPanel.setBorder(BorderFactory.createTitledBorder("Student Details"));

        formPanel.add(new JLabel("Student ID:"));
        idField = new JTextField();
        formPanel.add(idField);

        formPanel.add(new JLabel("Name:"));
        nameField = new JTextField();
        formPanel.add(nameField);

        formPanel.add(new JLabel("Age:"));
        ageField = new JTextField();
        formPanel.add(ageField);

        formPanel.add(new JLabel("Gender:"));
        genderBox = new JComboBox<>(new String[]{"Male", "Female", "Other"});
        formPanel.add(genderBox);

        formPanel.add(new JLabel("Department:"));
        departmentField = new JTextField();
        formPanel.add(departmentField);

        // Buttons Panel
        JPanel buttonPanel = new JPanel(new FlowLayout());
        JButton addButton = new JButton("Add");
        JButton updateButton = new JButton("Update");
        JButton deleteButton = new JButton("Delete");
        JButton viewButton = new JButton("View");

        buttonPanel.add(addButton);
        buttonPanel.add(updateButton);
        buttonPanel.add(deleteButton);
        buttonPanel.add(viewButton);

        // Table Panel
        tableModel = new DefaultTableModel(new String[]{"ID", "Name", "Age", "Gender", "Department"}, 0);
        table = new JTable(tableModel);
        JScrollPane tableScrollPane = new JScrollPane(table);

        // Add Panels to Frame
        frame.add(formPanel, BorderLayout.NORTH);
        frame.add(buttonPanel, BorderLayout.CENTER);
        frame.add(tableScrollPane, BorderLayout.SOUTH);

        // Button Action Listeners
        addButton.addActionListener(e -> addStudent());
        updateButton.addActionListener(e -> updateStudent());
        deleteButton.addActionListener(e -> deleteStudent());
        viewButton.addActionListener(e -> viewStudents());

        frame.setVisible(true);
    }

    private void addStudent() {
        try (Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/student_db","root", "Mihir@123")) {
            String sql = "INSERT INTO students (student_id, name, age, gender, department) VALUES (?, ?, ?, ?, ?)";
            PreparedStatement stmt = connection.prepareStatement(sql);
            stmt.setInt(1, Integer.parseInt(idField.getText()));
            stmt.setString(2, nameField.getText());
            stmt.setInt(3, Integer.parseInt(ageField.getText()));
            stmt.setString(4, genderBox.getSelectedItem().toString());
            stmt.setString(5, departmentField.getText());
            stmt.executeUpdate();
            JOptionPane.showMessageDialog(frame, "Student added successfully!");
            clearFields();
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(frame, "Error: " + ex.getMessage());
        }
    }

    private void updateStudent() {
        try (Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/student_db","root", "Mihir@123")) {
            String sql = "UPDATE students SET name = ?, age = ?, gender = ?, department = ? WHERE student_id = ?";
            PreparedStatement stmt = connection.prepareStatement(sql);
            stmt.setString(1, nameField.getText());
            stmt.setInt(2, Integer.parseInt(ageField.getText()));
            stmt.setString(3, genderBox.getSelectedItem().toString());
            stmt.setString(4, departmentField.getText());
            stmt.setInt(5, Integer.parseInt(idField.getText()));
            int rowsUpdated = stmt.executeUpdate();
            if (rowsUpdated > 0) {
                JOptionPane.showMessageDialog(frame, "Student updated successfully!");
                clearFields();
            } else {
                JOptionPane.showMessageDialog(frame, "Student not found!");
            }
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(frame, "Error: " + ex.getMessage());
        }
    }

    private void deleteStudent() {
        try (Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/student_db","root", "Mihir@123")) {
            String sql = "DELETE FROM students WHERE student_id = ?";
            PreparedStatement stmt = connection.prepareStatement(sql);
            stmt.setInt(1, Integer.parseInt(idField.getText()));
            int rowsDeleted = stmt.executeUpdate();
            if (rowsDeleted > 0) {
                JOptionPane.showMessageDialog(frame, "Student deleted successfully!");
                clearFields();
            } else {
                JOptionPane.showMessageDialog(frame, "Student not found!");
            }
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(frame, "Error: " + ex.getMessage());
        }
    }

    private void viewStudents() {
        try (Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/student_db","root", "Mihir@123")) {
            String sql = "SELECT * FROM students";
            Statement stmt = connection.createStatement();
            ResultSet rs = stmt.executeQuery(sql);
            tableModel.setRowCount(0); 
            while (rs.next()) {
                tableModel.addRow(new Object[]{
                        rs.getInt("student_id"),
                        rs.getString("name"),
                        rs.getInt("age"),
                        rs.getString("gender"),
                        rs.getString("department")
                });
            }
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(frame, "Error: " + ex.getMessage());
        }
    }

    private void clearFields() {
        idField.setText("");
        nameField.setText("");
        ageField.setText("");
        departmentField.setText("");
        genderBox.setSelectedIndex(0);
    }
}