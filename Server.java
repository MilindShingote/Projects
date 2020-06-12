import java.io.*;
import java.net.*;

class Server
{
	public static void main(String arg[])throws Exception
	{
		System.out.println("Server is Running");
			
		ServerSocket ss=new ServerSocket(1999);
		Socket s=ss.accept();
		BufferedReader Brk= new BufferedReader(new InputStreamReader(System.in));
		BufferedReader Brs= new BufferedReader(new InputStreamReader(s.getInputStream()));
		
		PrintStream ps=new PrintStream(s.getOutputStream());
		String str1,str2;
		while(true)
		{
			
			str1=Brs.readLine();
			if(str1==null)
			{
				break;
			}
			System.out.println("Massage from Client"+str1);
			System.out.println("Enter the massage for Client");
			str2=Brk.readLine();
			ps.println(str2);			
		}
	}
}
