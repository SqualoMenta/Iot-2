import javax.swing.SwingUtilities;

public class SimpleSerialMonitor {

    public static void main(String[] args) throws Exception {
        WasteContainerGUI view = new WasteContainerGUI();
        String comPortName;
        if (args.length != 1) {
            comPortName = "COM3";
        } else {
            comPortName = args[0];
        }
        System.out.println("Start monitoring serial port " + args[0] + " at 9600 boud rate");
        SwingUtilities.invokeAndWait(() -> {
            view.initGUI();
        });
        WasteContainerController controller = new WasteContainerController(comPortName, view);
        view.addController(controller);
        SwingUtilities.invokeLater(() -> {
            view.setVisible(true);
        });
    }
}
