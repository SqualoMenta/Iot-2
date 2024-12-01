import javax.swing.SwingUtilities;

public class SimpleSerialMonitor {

    public static void main(String[] args) throws Exception {
        WasteContainerGUI view = new WasteContainerGUI();
        if (args.length != 1) {
            System.out.println("args: <CommPortName>");
            System.exit(1);
        } else {
            String comPortName = args[0];
            System.out.println("Start monitoring serial port " + args[0] + " at 9600 boud rate");
            SwingUtilities.invokeAndWait(()->{
                view.initGUI();
            });
            WasteContainerController controller = new WasteContainerController(comPortName, view);
            view.addController(controller);
            SwingUtilities.invokeLater(() -> {
                view.setVisible(true);
            });
        }
    }
}
