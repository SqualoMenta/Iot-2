import javax.swing.SwingUtilities;

public class WasteContainerController  {
	
	SerialCommChannel channel;
	WasteContainerGUI view;
	
	public WasteContainerController(String port, WasteContainerGUI view) throws Exception {
		this.view = view;
		
		channel = new SerialCommChannel(port,9600);		
		new MonitoringAgent(channel, this).start();	
	
	}

    setUpTemp(String temp){
        SwingUtilities.invokeLater(view.setUpTemp());
    }
	

    setUpFullness(String fullness){
        SwingUtilities.invokeLater(view.setUpFullness());
    }
}
