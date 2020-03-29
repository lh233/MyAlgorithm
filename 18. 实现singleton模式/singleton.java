//很明显只适合单线程模式
public sealed class Singleton1
{
	private Singleton1()
	{
		
	}
	private static Singleton1 instance = null;
	public static Singleton1 Instance
	{
		get
		{
			if(instance == null)
				instance = new Singleton1();
			return instance;
		}
	}
}




//虽然在多线程环境下工作，但效率不高
public sealed class Singleton2
{
	private Singleton2()
	{
		
	}
	
	private static readonly syncObj = new object();
	private static Singleton2 instance = null;
	private static Singleton2 Instance
	{
		get
		{
			lock(syncObj)
			{
				if(instance == null)
					instance = new Singleton2();
			}	
			return instance;
		}
	}
}



//强烈推荐的解法：
public sealed class Singleton3
{
	private Singleton3()
	{
		
	}
	
	private static Singleton3 instance = new Singleton3();
	public static Singleton3 Instance
	{
		get
		{
			return instance;
		}
}
