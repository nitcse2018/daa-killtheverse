package awt_assignment;

import java.awt.*;
import java.awt.event.*;
import java.io.FileWriter;
import java.io.IOException;


public class Resume {
	private Frame frame;
	private TextField nameField;
	private TextField emailField;
	private TextField contactField;
	private TextField educationField;
	private TextField projectField;
	private TextField experienceField;
	private TextField activityField;
	private TextField skillField;
	public Resume(){
		frame = new Frame("Resume builder");
		frame.setSize(900, 900);
		frame.setLayout(new GridLayout(9, 2));
		frame.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent windowEvent){
				System.exit(0);
			}
		});
		Label nameLabel = new Label("Name:");
		Label educationLabel = new Label("Education:");
		Label experienceLabel = new Label("Work Experience:");
		Label emailLabel = new Label("Email:");
		Label contactLabel = new Label("Contact number:");
		Label skillLabel = new Label("Skills:");
		Label projectLabel = new Label("Projects:");
		Label activityLabel = new Label("Extra Curricular Activities:");
		nameLabel.setAlignment(Label.CENTER);
		educationLabel.setAlignment(Label.CENTER);
		experienceLabel.setAlignment(Label.CENTER);
		emailLabel.setAlignment(Label.CENTER);
		contactLabel.setAlignment(Label.CENTER);
		skillLabel.setAlignment(Label.CENTER);
		projectLabel.setAlignment(Label.CENTER);
		activityLabel.setAlignment(Label.CENTER);
		
		nameField = new TextField();
		educationField = new TextField();
		experienceField = new TextField();
		emailField = new TextField();
		contactField = new TextField();
		skillField = new TextField();
		projectField = new TextField();
		activityField = new TextField();
		
		nameField.setColumns(45);
		educationField.setColumns(45);
		experienceField.setColumns(45);
		emailField.setColumns(45);
		contactField.setColumns(45);
		skillField.setColumns(45);
		projectField.setColumns(45);
		activityField.setColumns(45);
		
		Button resetButton = new Button("Reset");
	    Button submitButton = new Button("Submit");
		
		frame.add(nameLabel);
		frame.add(nameField);

		frame.add(emailLabel);
		frame.add(emailField);
		
		frame.add(contactLabel);
		frame.add(contactField);
		
		frame.add(educationLabel);
		frame.add(educationField);
		
		frame.add(experienceLabel);
		frame.add(experienceField);
		
		frame.add(projectLabel);
		frame.add(projectField);
		
		frame.add(skillLabel);
		frame.add(skillField);
		
		frame.add(activityLabel);
		frame.add(activityField);
		
		frame.add(resetButton);
		frame.add(submitButton);
		
		resetButton.setActionCommand("Reset");
	    submitButton.setActionCommand("Submit");
	    resetButton.addActionListener(new ButtonClickListener()); 
	    submitButton.addActionListener(new ButtonClickListener()); 
	      
		frame.setVisible(true);
	}
	public class ButtonClickListener implements ActionListener {
	    public void actionPerformed(ActionEvent e) {
	        String command = e.getActionCommand();  
	        System.out.print(command);
	        System.out.print(nameField.getText());
	        System.out.print(emailField.getText());
	        System.out.print(contactField.getText());
	        System.out.print(skillField.getText());
	        System.out.print(educationField.getText());
	        System.out.print(experienceField.getText());
	        System.out.print(projectField.getText());
	        System.out.print(activityField.getText());
	        if( command.equals( "Reset" ))  {
	        	 nameField.setText("");
	        	 emailField.setText("");
	        	 contactField.setText("");
	        	 skillField.setText("");
	        	 educationField.setText("");
	        	 experienceField.setText("");
	        	 projectField.setText("");
	        	 activityField.setText("");
	        }
	        else if( command.equals( "Submit" ) )  {
	        	try {
					FileWriter fw = new FileWriter("output.txt", true);
					String s = nameField.getText();
					fw.write("NAME:");
					for(int i=0;i<s.length();i++){
						fw.write(s.charAt(i));
					}
					fw.write("\n");
					
					s = emailField.getText();
					fw.write("EMAIL:");
					for(int i=0;i<s.length();i++){
						fw.write(s.charAt(i));
					}
					fw.write("\n");
					s = contactField.getText();
					fw.write("CONTACT NUMBER:");
					for(int i=0;i<s.length();i++){
						fw.write(s.charAt(i));
					}
					fw.write("\n");
					s = educationField.getText();
					fw.write("EDUCATION:");
					for(int i=0;i<s.length();i++){
						fw.write(s.charAt(i));
					}
					fw.write("\n");
					s = experienceField.getText();
					fw.write("EXPERIENCE:");
					for(int i=0;i<s.length();i++){
						fw.write(s.charAt(i));
					}
					fw.write("\n");
					s = projectField.getText();
					fw.write("PROJECTS:");
					for(int i=0;i<s.length();i++){
						fw.write(s.charAt(i));
					}
					fw.write("\n");
					s = skillField.getText();
					fw.write("SKILLS:");
					for(int i=0;i<s.length();i++){
						fw.write(s.charAt(i));
					}
					fw.write("\n");
					s = activityField.getText();
					fw.write("EXTRA CURRICULAR ACTIVITIES:");
					for(int i=0;i<s.length();i++){
						fw.write(s.charAt(i));
					}
					fw.write("\n");
					fw.write("\n---------------------------------------------------------------\n");
					fw.close();
					System.out.println("SUCCESS");
				} catch (IOException e1) {
					e1.printStackTrace();
				}
	        	
	        } 	
	    }		
	}
	public static void main(String[] args){
		Resume resume = new Resume();
	}
}
