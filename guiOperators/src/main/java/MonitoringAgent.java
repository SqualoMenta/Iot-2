public class MonitoringAgent extends Thread {

	CommChannel channel;
	WasteContainerController controller;

    final String ARDUINO_PREFIX = "OUT::";
    final String TEMPERATURE_PREFIX = "T:";
    final String FULLNESS_PREFIX = "W:";
    final String PROBLEM_STR = "P";
	
    public MonitoringAgent(CommChannel channel, WasteContainerController view) throws Exception {
		this.controller = controller;
		this.channel = channel;
	}
	
	public void run(){
		boolean inMaintenance = true;
		while (true){
			try {
				String msg = channel.receiveMsg();
				if (msg.startsWith(ARDUINO_PREFIX)){
					String cmd = msg.substring(ARDUINO_PREFIX.length()); 
					// logger.log("new command: "+cmd);				
					
					if (cmd.startsWith(TEMPERATURE_PREFIX)){
						try {
							String arg = cmd.substring(TEMPERATURE_PREFIX.length());
                            
                            controller.setUpTemp(arg);
							
							String[] elems = arg.split(":");
							/*if (elems.length >= 3) {
								int stateCode = Integer.parseInt(elems[0]);
								int numWashes = Integer.parseInt(elems[1]);
								double temp = Double.parseDouble(elems[2]);
		
								view.setNumWashes(numWashes);
								view.setCurrentTemperature(temp);
								view.setPlantState(stateNames[stateCode]);
								
								if (stateCode == 5 && !inMaintenance) { // maintenance
									inMaintenance = true;
									view.enableMaintenance();
								} else if (stateCode != 5 && inMaintenance) {
									inMaintenance = false;
									
								}
							}*/
						} catch (Exception ex) {
							ex.printStackTrace();
							System.err.println("Error in msg: " + cmd);
						}
					}
				} else if (msg.startsWith(LOG_PREFIX)){
					this.logger.log(msg.substring(LOG_PREFIX.length()));
				}
			} catch (Exception ex){
				ex.printStackTrace();
			}
		}
	}

}
