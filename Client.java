import java.io.*;
import java.net.*;

class Client
{
	public static void main(String arg[])throws Exception
	{
		System.out.println("Client is Running");
			
		Socket s=new Socket("localhost",1999);
		BufferedReader Brk= new BufferedReader(new InputStreamReader(System.in));
		BufferedReader Brs= new BufferedReader(new InputStreamReader(s.getInputStream()));
		
		PrintStream ps=new PrintStream(s.getOutputStream());
		String str1,str2;
		while(true)
		{
			System.out.println("Enter the massage for Server");
			str1=Brk.readLine();
			if(str1.equals("Exit"))
			{
				break;
			}
			ps.println(str1);
			str2=Brs.readLine();
			System.out.println("Massage from Server"+str2);
		}
	}
}
