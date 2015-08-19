#include <windows.h>
#include <stdio.h>

#include <string.h>

LRESULT  CALLBACK WindowsFunc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
//窗口函数声明
TCHAR szWinName[]="myWin";

TCHAR str[255]="";

int WINAPI  WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)//winmain函数定义
{
	
	
	HWND hWnd;//窗口句柄
	
	
	
	MSG msg;//消息结构体
	
	WNDCLASSEX wcl;//窗口结构体
	
	wcl.cbSize=sizeof(WNDCLASSEX);
	wcl.hInstance=hInstance;//当前应用程序实例句柄
	wcl.lpfnWndProc=WindowsFunc;//本窗口的消息处理函数
	wcl.lpszClassName=szWinName;//给窗口结构体命名
	wcl.style=0;//窗口风格
	wcl.hIcon=LoadIcon(NULL,IDI_APPLICATION);//窗口图标，标准图标
	//wcl.hIconSm=LoadIcon(NULL,IDC_WINLOGO);
	wcl.lpszMenuName=NULL;//窗口菜单，没有菜单
	wcl.cbClsExtra=0;//附加参数
	wcl.cbWndExtra=0;//附加参数
	wcl.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);//窗口背景色
	
	if(!RegisterClassEx(&wcl))return 0;
	RegisterClassEx(&wcl);
	
	
	hWnd=CreateWindow(
		szWinName,//窗口结构体名称
		"chuangkou",//窗口标题
		WS_OVERLAPPEDWINDOW,//窗口风格为可重叠窗口
		//4个参数代表窗口左上角x,y坐标和窗口的宽度和高度，都是用默认值
		//0,0,600,400,
		
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		//下面参数分别为父窗口句柄、窗口菜单句柄、应用程序实例句柄、附加参数
		HWND_DESKTOP,NULL,hInstance,NULL);
	MessageBox(hWnd,"fef","RBUTTONPUSHDOWN",0);
	ShowWindow(hWnd,nCmdShow);//显示最大化窗口
	UpdateWindow(hWnd);//更新窗口
	MessageBox(hWnd,"fef","RBUTTONPUSHDOWN",0);
	
		  while(GetMessage(&msg,NULL,0,0)) //消息循环，获取消息，填充msg结构体
		  {
			  TranslateMessage(&msg);//翻译键盘信息
			  DispatchMessage(&msg);//向窗口函数发送信息，让窗口函数处理
		  }
		  return msg.wParam;
}
LRESULT  CALLBACK WindowsFunc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)//窗口函数定义
{
		  char messageleft[]="the left button";
		  char messageright[]="the right button";
		  switch(message)
		  {
		  case WM_RBUTTONDOWN:
			  
			  MessageBox(hWnd,messageright,"RBUTTONPUSHDOWN",0);
			  break;
			  
		  case WM_LBUTTONDOWN:
			  
			  MessageBox(GetFocus(),messageleft,"LBUTTONPUSHDOWN",MB_OK|MB_ICONINFORMATION);
			  break;
			  
		  case WM_DESTROY:
			  
			  PostQuitMessage(0);
			  break;
			  
		  default:
			  return DefWindowProc(hWnd,message,wParam,lParam);;
		  }
		  return 0;
}


/*#include <windows.h>
#include <stdio.h>
//回调函数，注意CALLBACK关键字不能掉，表明的是一种操作系统从消息队列中调用消息的一种方式。该函数的名字可以对边起，其其实就是一种对MSG消息前几个变量
LRESULT CALLBACK WinTotem(
HWND hwnd,      // handle to window
UINT uMsg,      // message identifier
WPARAM wParam,  // first message parameter
LPARAM lParam   // second message parameter
);
//应用程序入口，其参数由操作系统自动赋值

  int WINAPI WinMain(
  
	HINSTANCE hInstance,      // handle to current instance
	HINSTANCE hPrevInstance,  // handle to previous instance
	LPSTR lpCmdLine,          // command line
	int nCmdShow              // show state
	)
	
	  {	
	  //设计窗口类	
	  WNDCLASS wndcls;	
	  //额外分配的内存	
	  wndcls.cbClsExtra=0;	
	  wndcls.cbWndExtra=0;	
	  //设置背景色，HBRUSH画刷	
	  wndcls.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);	
	  //设置光标的类型.采用标准的类型时候第一个参数设置为NULL	
	  wndcls.hCursor=LoadCursor(NULL,IDC_CROSS);	
	  //设置图标的类型，采用标准类型的时候第一个参数为NULL	
	  wndcls.hIcon=LoadIcon(NULL,IDI_ERROR);	
	  //当前实例标识	
	  wndcls.hInstance=hInstance;	
	  //指定回调函数	
	  wndcls.lpfnWndProc=WinTotem;	
	  //指定类型名称，就如手机的型号	
	  wndcls.lpszClassName="Totem";
	  //指定菜单的名称，没有菜单时设置为NULL	
	  wndcls.lpszMenuName=NULL;	
	  //设置窗口的类型由|&~连接各种属性	
	  wndcls.style=CS_HREDRAW | CS_VREDRAW;		
	  //注册窗口类，手机设计好了必须到工商局注册一下才能生产啊	
	  RegisterClass(&wndcls);	
	  //产生窗口	
	  HWND hwnd;	
	  hwnd=CreateWindow("Totem","我的第一个MFC程序",WS_OVERLAPPEDWINDOW,
	  
		0,0,600,400,NULL,NULL,hInstance,NULL);			
		//显示窗口	
		ShowWindow(hwnd,SW_SHOWNORMAL);	
		//刷新窗口	
		UpdateWindow(hwnd);	
		MSG msg;	
		//每次从系统的消息队列中取出一条消息	
		while(GetMessage(&msg,NULL,0,0))		
		{		
		//将消息交给操作系统		
		TranslateMessage(&msg);			//操作系统将消息传给回调函数处理		
		DispatchMessage(&msg);		
		}	
		return 0;
		
		  }
		  
			
			  
				//回调函数的实现
				
				  LRESULT CALLBACK WinTotem(
				  
					HWND hwnd,      // handle to window
					
					  UINT uMsg,      // message identifier
					  
						WPARAM wParam,  // first message parameter
						
						  LPARAM lParam   // second message parameter
						  
							)
							
							  {
							  
								//对不同的消息类型进行处理
								
								  switch(uMsg)
								  
									{
									
									  //键盘消息
									  
										case WM_CHAR:
										
										  char szChar[20];
										  
											//根据参数对键盘进行判断，将字符串标准格式化输入到内存
											
											  //sprintf(szChar,"char is %d",wParam);
											  
												MessageBox(hwnd,szChar,"weixin",0);
												
												  break;
												  
													//鼠标左键按下
													
													  case WM_LBUTTONDOWN:
													  
														MessageBox(hwnd,"mouse clicked","世界之窗",0);
														
														  //设备上下文环境
														  
															HDC hdc;
															
															  hdc=GetDC(hwnd);
															  
																TextOut(hdc,0,50,"世界你好",strlen("世界你好"));
																
																  //用完后记得要释放DC
																  
																	ReleaseDC(hwnd,hdc);
																	
																	  break;
																	  
																		//窗口重绘，这里的DC获取和释放和前面不一样哦亲，而且还不能替换呢
																		
																		  case WM_PAINT:
																		  
																			HDC hDC;
																			
																			  PAINTSTRUCT ps;
																			  
																				hDC=BeginPaint(hwnd,&ps);
																				
																				  TextOut(hDC,0,0,"世界之窗",strlen("世界之窗"));
																				  
																					EndPaint(hwnd,&ps);
																					
																					  break;
																					  
																						//关闭窗口
																						
																						  case WM_CLOSE:
																						  
																							if(IDYES==MessageBox(hwnd,"是否真的结束？","weixin",MB_YESNO))
																							
																							  {
																							  
																								DestroyWindow(hwnd);
																								
																								  }
																								  
																									break;
																									
																									  //这里有点小技巧哦，由DestroyWindow（）发出的消息引发下列函数的处理，如果没有下列函数的处理可能就会产生窗口不显示但是进程还在后台运行的现象。
																									  case WM_DESTROY:
																									  
																										PostQuitMessage(0);
																										
																										  break;
																										  
																											//将其它情况用默认的方式理
																											
																											  default:
																											  return DefWindowProc(hwnd,uMsg,wParam,lParam);
																											  }
																											  return 0;
}*/
