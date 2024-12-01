import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class WasteContainerGUI {
    private JFrame frame;
    private JLabel wasteLevelLabel;
    private JLabel temperatureLabel;
    private JTextArea statusArea;
    private WasteContainerController controller;
    private JButton restoreButton;
    private JButton emptyButton;

    public void addController(WasteContainerController controller) {
        this.controller = controller;
    }

    public void initGUI() {
        frame = new JFrame("Waste Container Monitor");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);
        frame.setLayout(new BorderLayout());

        // Top panel for status
        JPanel topPanel = new JPanel(new GridLayout(2, 1));
        wasteLevelLabel = new JLabel("Waste Level: N/A");
        temperatureLabel = new JLabel("Temperature: N/A");
        topPanel.add(wasteLevelLabel);
        topPanel.add(temperatureLabel);
        frame.add(topPanel, BorderLayout.NORTH);

        // Center panel for logs
        statusArea = new JTextArea();
        statusArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(statusArea);
        frame.add(scrollPane, BorderLayout.CENTER);

        // Bottom panel for buttons
        JPanel buttonPanel = new JPanel(new FlowLayout());
        JButton emptyButton = new JButton("EMPTY");
        JButton restoreButton = new JButton("RESTORE");

        buttonPanel.add(emptyButton);
        buttonPanel.add(restoreButton);
        frame.add(buttonPanel, BorderLayout.SOUTH);
        restoreButton.setEnabled(false);

        // Button actions
        emptyButton.addActionListener(_ -> clickClean());
        restoreButton.addActionListener(_ -> clickRestore());

        frame.addWindowListener(new java.awt.event.WindowAdapter() {
            @Override
            public void windowClosing(java.awt.event.WindowEvent e) {
                if (controller != null) {
                    controller.shutdown(); // Call shutdown on the controller
                }
            }
        });
    }

    private void clickClean() {
        controller.sendClean();
    }

    private void clickRestore() {
        controller.sendRestore();
        restoreButton.setEnabled(false);
    }

    public void setUpTemp(String temp) {
        temperatureLabel.setText("Temperature: " + temp);
        statusArea.append("Received: Temperature\n");
    }

    public void setUpFullness(String fullness) {
        wasteLevelLabel.setText("Waste Level: " + fullness);
        if (Double.parseDouble(fullness) <= 0) {
            emptyButton.setEnabled(false);
        }else{
            emptyButton.setEnabled(true);
        }
        statusArea.append("Received: fullness\n");
    }

    public void setVisible(boolean b) {
        frame.setVisible(b);
    }

    public void problemTemp() {
        statusArea.append("Received: problem\n");
        restoreButton.setEnabled(true);
    }
}