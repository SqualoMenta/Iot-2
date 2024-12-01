import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.SwingUtilities;

public class WasteContainerGUI {
    private JFrame frame;
    private JLabel wasteLevelLabel;
    private JLabel temperatureLabel;
    private JTextArea statusArea;
    private WasteContainerController controller;

    public WasteContainerGUI() {
        initGUI();
        startDataListener();
    }

    public void addController(WasteContainerController controller){
        this.controller = controller;
    }

    private void initGUI() {
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

        // Button actions
        emptyButton.addActionListener(e -> sendCommand("EMPTY"));
        restoreButton.addActionListener(e -> sendCommand("RESTORE"));

        frame.setVisible(true);
    }

    private void sendCommand(String command) {
        try {
            controller.sendMsg(command);
            statusArea.append("Sent command: " + command + "\n");
        } catch (Exception ex) {
            statusArea.append("Error sending command: " + ex.getMessage() + "\n");
        }
    }

    private void startDataListener() {
        new Thread(() -> {
            while (true) {
                try {
                    if (channel.isMsgAvailable()) {
                        String msg = channel.receiveMsg();
                        processMessage(msg);
                    }
                } catch (Exception ex) {
                    statusArea.append("Error receiving data: " + ex.getMessage() + "\n");
                }
            }
        }).start();
    }

    private void processMessage(String msg) {
        SwingUtilities.invokeLater(() -> {
            statusArea.append("Received: " + msg + "\n");
            if (msg.startsWith("LEVEL:")) {
                wasteLevelLabel.setText("Waste Level: " + msg.substring(6));
            } else if (msg.startsWith("TEMP:")) {
                temperatureLabel.setText("Temperature: " + msg.substring(5));
            } else if (msg.startsWith("ALARM")) {
                JOptionPane.showMessageDialog(frame, "Alarm detected!", "Warning", JOptionPane.WARNING_MESSAGE);
            }
        });
    }
}