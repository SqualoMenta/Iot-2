package guioperators;

import java.awt.*;
import javax.swing.*;

public class WasteContainerGUI {
    private JFrame frame;
    private JLabel temperatureLabel;
    private JProgressBar fullnessBar;
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
        frame.setSize(500, 400);
        frame.setLayout(new BorderLayout());

        // Top panel for status
        JPanel topPanel = new JPanel(new GridLayout(2, 1));
        fullnessBar = new JProgressBar(0, 100);
        fullnessBar.setStringPainted(true);
        fullnessBar.setForeground(Color.GREEN);

        temperatureLabel = new JLabel("Temperature: N/A", SwingConstants.CENTER);
        temperatureLabel.setOpaque(true);
        temperatureLabel.setFont(new Font("Arial", Font.BOLD, 16));

        topPanel.add(fullnessBar);
        topPanel.add(temperatureLabel);
        frame.add(topPanel, BorderLayout.NORTH);

        // Center panel for logs
        statusArea = new JTextArea();
        statusArea.setEditable(false);
        statusArea.setFont(new Font("Monospaced", Font.PLAIN, 12));
        JScrollPane scrollPane = new JScrollPane(statusArea);
        frame.add(scrollPane, BorderLayout.CENTER);

        // Bottom panel for buttons
        JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 20, 10));
        emptyButton = new JButton("EMPTY");
        restoreButton = new JButton("RESTORE");
        restoreButton.setEnabled(false);

        buttonPanel.add(emptyButton);
        buttonPanel.add(restoreButton);
        frame.add(buttonPanel, BorderLayout.SOUTH);

        // Button actions
        emptyButton.addActionListener(e -> clickClean());
        restoreButton.addActionListener(e -> clickRestore());

        frame.addWindowListener(new java.awt.event.WindowAdapter() {
            @Override
            public void windowClosing(java.awt.event.WindowEvent e) {
                if (controller != null) {
                    controller.shutdown();
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
        double temperature = Double.parseDouble(temp);
        temperatureLabel.setText("Temperature: " + temp + "°C");

        if (temperature > 24) {
            temperatureLabel.setBackground(Color.RED);
            temperatureLabel.setForeground(Color.WHITE);
        } else {
            temperatureLabel.setBackground(Color.GREEN);
            temperatureLabel.setForeground(Color.BLACK);
        }

        statusArea.append("Temperature updated: " + temp + "°C\n");
    }

    public void setUpFullness(String fullness) {
        int fullnessValue = Integer.parseInt(fullness);
        fullnessBar.setValue(fullnessValue);

        if (fullnessValue < 50) {
            fullnessBar.setForeground(Color.GREEN);
        } else if (fullnessValue < 80) {
            fullnessBar.setForeground(Color.ORANGE);
        } else {
            fullnessBar.setForeground(Color.RED);
        }

        fullnessBar.setString("Waste Level: " + fullnessValue + "%");
        statusArea.append("Waste level updated: " + fullnessValue + "%\n");
    }

    public void setVisible(boolean b) {
        frame.setVisible(b);
    }

    public void problemTemp() {
        statusArea.append("Temperature problem detected!\n");
        restoreButton.setEnabled(true);
    }
}
