package postmid;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class quiz extends JFrame implements ActionListener {

    private JLabel questionLabel;
    private JRadioButton option1, option2, option3, option4;
    private JButton submitButton, nextButton, finishButton;
    private ButtonGroup optionsGroup;
    private int currentQuestion = 0;
    private int score = 0;

    // Sample questions, options, and correct answers
    private String[] questions = {
        "What is the capital of France?",
        "Which planet is known as the Red Planet?",
        "What is the largest mammal?",
        "Who developed the theory of relativity?"
    };

    private String[][] options = {
        {"Berlin", "Madrid", "Paris", "Lisbon"},
        {"Earth", "Mars", "Jupiter", "Venus"},
        {"Elephant", "Blue Whale", "Giraffe", "Great White Shark"},
        {"Isaac Newton", "Albert Einstein", "Galileo Galilei", "Nikola Tesla"}
    };

    private int[] correctAnswers = {2, 1, 1, 1};

    public quiz() {
        setTitle("Quiz Application");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        
        // Question label and options
        questionLabel = new JLabel();
        option1 = new JRadioButton();
        option2 = new JRadioButton();
        option3 = new JRadioButton();
        option4 = new JRadioButton();

        optionsGroup = new ButtonGroup();
        optionsGroup.add(option1);
        optionsGroup.add(option2);
        optionsGroup.add(option3);
        optionsGroup.add(option4);

        // Buttons
        submitButton = new JButton("Submit");
        nextButton = new JButton("Next");
        finishButton = new JButton("Finish");

        submitButton.addActionListener(this);
        nextButton.addActionListener(this);
        finishButton.addActionListener(this);

        finishButton.setEnabled(false);

        // Panel layout
        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
        panel.add(questionLabel);
        panel.add(option1);
        panel.add(option2);
        panel.add(option3);
        panel.add(option4);
        panel.add(submitButton);
        panel.add(nextButton);
        panel.add(finishButton);

        add(panel);
        displayQuestion();

        setVisible(true);
    }

    private void displayQuestion() {
        // Display current question and options
        questionLabel.setText("Q" + (currentQuestion + 1) + ": " + questions[currentQuestion]);
        option1.setText(options[currentQuestion][0]);
        option2.setText(options[currentQuestion][1]);
        option3.setText(options[currentQuestion][2]);
        option4.setText(options[currentQuestion][3]);
        optionsGroup.clearSelection();

        // Enable/Disable buttons
        submitButton.setEnabled(true);
        nextButton.setEnabled(false);
        if (currentQuestion == questions.length - 1) {
            nextButton.setEnabled(false);
            finishButton.setEnabled(true);
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == submitButton) {
            int selectedOption = getSelectedOption();
            if (selectedOption == correctAnswers[currentQuestion]) {
                score++;
            }
            submitButton.setEnabled(false);
            nextButton.setEnabled(true);
        } else if (e.getSource() == nextButton) {
            currentQuestion++;
            displayQuestion();
        } else if (e.getSource() == finishButton) {
            JOptionPane.showMessageDialog(this, "Quiz finished! Your final score is: " + score + "/" + questions.length);
            System.exit(0);
        }
    }

    private int getSelectedOption() {
        if (option1.isSelected()) return 0;
        if (option2.isSelected()) return 1;
        if (option3.isSelected()) return 2;
        if (option4.isSelected()) return 3;
        return -1; // No option selected
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(quiz::new);
    }
}