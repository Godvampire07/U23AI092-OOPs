package postmid;
import javax.swing.*;// imports jfram,jlabel
import java.text.SimpleDateFormat;///styling
import java.util.Date; //for current date
import javax.swing.Timer;//jawa timer for udating time

public class DigitalClockApplet  {
    
    public static void main(String[] args) {	
        DCA clock = new DCA();
        clock.setSize(400, 200);
        clock.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        clock.setVisible(true);
    }
}
class DCA extends JFrame{
	private JLabel timeLabel;
    private SimpleDateFormat timeFormat;
    public  DCA() {
        // Initialize the time format and label
        timeFormat = new SimpleDateFormat("EEEEEEEEEE MMMMM d, yyyy - HH:mm:ss");
        timeLabel = new JLabel();
        timeLabel.setHorizontalAlignment(SwingConstants.CENTER);
        
        // Add the label to the applet
        add(timeLabel);
        
        // Create a Timer to update the time every second
        Timer timer = new Timer(1000, e -> updateTime());
        timer.start();
    }

    // Update the JLabel with the current time
    private void updateTime() {
        String currentTime = timeFormat.format(new Date());
        timeLabel.setText(currentTime);
    }	
}
