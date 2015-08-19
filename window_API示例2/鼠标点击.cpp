#include <windows.h>
#include <stdio.h>

#include <string.h>

LRESULT  CALLBACK WindowsFunc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
//���ں�������
TCHAR szWinName[]="myWin";

TCHAR str[255]="";

int WINAPI  WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)//winmain��������
{
	
	
	HWND hWnd;//���ھ��
	
	
	
	MSG msg;//��Ϣ�ṹ��
	
	WNDCLASSEX wcl;//���ڽṹ��
	
	wcl.cbSize=sizeof(WNDCLASSEX);
	wcl.hInstance=hInstance;//��ǰӦ�ó���ʵ�����
	wcl.lpfnWndProc=WindowsFunc;//�����ڵ���Ϣ������
	wcl.lpszClassName=szWinName;//�����ڽṹ������
	wcl.style=0;//���ڷ��
	wcl.hIcon=LoadIcon(NULL,IDI_APPLICATION);//����ͼ�꣬��׼ͼ��
	//wcl.hIconSm=LoadIcon(NULL,IDC_WINLOGO);
	wcl.lpszMenuName=NULL;//���ڲ˵���û�в˵�
	wcl.cbClsExtra=0;//���Ӳ���
	wcl.cbWndExtra=0;//���Ӳ���
	wcl.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);//���ڱ���ɫ
	
	if(!RegisterClassEx(&wcl))return 0;
	RegisterClassEx(&wcl);
	
	
	hWnd=CreateWindow(
		szWinName,//���ڽṹ������
		"chuangkou",//���ڱ���
		WS_OVERLAPPEDWINDOW,//���ڷ��Ϊ���ص�����
		//4���������������Ͻ�x,y����ʹ��ڵĿ�Ⱥ͸߶ȣ�������Ĭ��ֵ
		//0,0,600,400,
		
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		//��������ֱ�Ϊ�����ھ�������ڲ˵������Ӧ�ó���ʵ����������Ӳ���
		HWND_DESKTOP,NULL,hInstance,NULL);
	MessageBox(hWnd,"fef","RBUTTONPUSHDOWN",0);
	ShowWindow(hWnd,nCmdShow);//��ʾ��󻯴���
	UpdateWindow(hWnd);//���´���
	MessageBox(hWnd,"fef","RBUTTONPUSHDOWN",0);
	
		  while(GetMessage(&msg,NULL,0,0)) //��Ϣѭ������ȡ��Ϣ�����msg�ṹ��
		  {
			  TranslateMessage(&msg);//���������Ϣ
			  DispatchMessage(&msg);//�򴰿ں���������Ϣ���ô��ں�������
		  }
		  return msg.wParam;
}
LRESULT  CALLBACK WindowsFunc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)//���ں�������
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
//�ص�������ע��CALLBACK�ؼ��ֲ��ܵ�����������һ�ֲ���ϵͳ����Ϣ�����е�����Ϣ��һ�ַ�ʽ���ú��������ֿ��ԶԱ�������ʵ����һ�ֶ�MSG��Ϣǰ��������
LRESULT CALLBACK WinTotem(
HWND hwnd,      // handle to window
UINT uMsg,      // message identifier
WPARAM wParam,  // first message parameter
LPARAM lParam   // second message parameter
);
//Ӧ�ó�����ڣ�������ɲ���ϵͳ�Զ���ֵ

  int WINAPI WinMain(
  
	HINSTANCE hInstance,      // handle to current instance
	HINSTANCE hPrevInstance,  // handle to previous instance
	LPSTR lpCmdLine,          // command line
	int nCmdShow              // show state
	)
	
	  {	
	  //��ƴ�����	
	  WNDCLASS wndcls;	
	  //���������ڴ�	
	  wndcls.cbClsExtra=0;	
	  wndcls.cbWndExtra=0;	
	  //���ñ���ɫ��HBRUSH��ˢ	
	  wndcls.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);	
	  //���ù�������.���ñ�׼������ʱ���һ����������ΪNULL	
	  wndcls.hCursor=LoadCursor(NULL,IDC_CROSS);	
	  //����ͼ������ͣ����ñ�׼���͵�ʱ���һ������ΪNULL	
	  wndcls.hIcon=LoadIcon(NULL,IDI_ERROR);	
	  //��ǰʵ����ʶ	
	  wndcls.hInstance=hInstance;	
	  //ָ���ص�����	
	  wndcls.lpfnWndProc=WinTotem;	
	  //ָ���������ƣ������ֻ����ͺ�	
	  wndcls.lpszClassName="Totem";
	  //ָ���˵������ƣ�û�в˵�ʱ����ΪNULL	
	  wndcls.lpszMenuName=NULL;	
	  //���ô��ڵ�������|&~���Ӹ�������	
	  wndcls.style=CS_HREDRAW | CS_VREDRAW;		
	  //ע�ᴰ���࣬�ֻ���ƺ��˱��뵽���̾�ע��һ�²���������	
	  RegisterClass(&wndcls);	
	  //��������	
	  HWND hwnd;	
	  hwnd=CreateWindow("Totem","�ҵĵ�һ��MFC����",WS_OVERLAPPEDWINDOW,
	  
		0,0,600,400,NULL,NULL,hInstance,NULL);			
		//��ʾ����	
		ShowWindow(hwnd,SW_SHOWNORMAL);	
		//ˢ�´���	
		UpdateWindow(hwnd);	
		MSG msg;	
		//ÿ�δ�ϵͳ����Ϣ������ȡ��һ����Ϣ	
		while(GetMessage(&msg,NULL,0,0))		
		{		
		//����Ϣ��������ϵͳ		
		TranslateMessage(&msg);			//����ϵͳ����Ϣ�����ص���������		
		DispatchMessage(&msg);		
		}	
		return 0;
		
		  }
		  
			
			  
				//�ص�������ʵ��
				
				  LRESULT CALLBACK WinTotem(
				  
					HWND hwnd,      // handle to window
					
					  UINT uMsg,      // message identifier
					  
						WPARAM wParam,  // first message parameter
						
						  LPARAM lParam   // second message parameter
						  
							)
							
							  {
							  
								//�Բ�ͬ����Ϣ���ͽ��д���
								
								  switch(uMsg)
								  
									{
									
									  //������Ϣ
									  
										case WM_CHAR:
										
										  char szChar[20];
										  
											//���ݲ����Լ��̽����жϣ����ַ�����׼��ʽ�����뵽�ڴ�
											
											  //sprintf(szChar,"char is %d",wParam);
											  
												MessageBox(hwnd,szChar,"weixin",0);
												
												  break;
												  
													//����������
													
													  case WM_LBUTTONDOWN:
													  
														MessageBox(hwnd,"mouse clicked","����֮��",0);
														
														  //�豸�����Ļ���
														  
															HDC hdc;
															
															  hdc=GetDC(hwnd);
															  
																TextOut(hdc,0,50,"�������",strlen("�������"));
																
																  //�����ǵ�Ҫ�ͷ�DC
																  
																	ReleaseDC(hwnd,hdc);
																	
																	  break;
																	  
																		//�����ػ棬�����DC��ȡ���ͷź�ǰ�治һ��Ŷ�ף����һ������滻��
																		
																		  case WM_PAINT:
																		  
																			HDC hDC;
																			
																			  PAINTSTRUCT ps;
																			  
																				hDC=BeginPaint(hwnd,&ps);
																				
																				  TextOut(hDC,0,0,"����֮��",strlen("����֮��"));
																				  
																					EndPaint(hwnd,&ps);
																					
																					  break;
																					  
																						//�رմ���
																						
																						  case WM_CLOSE:
																						  
																							if(IDYES==MessageBox(hwnd,"�Ƿ���Ľ�����","weixin",MB_YESNO))
																							
																							  {
																							  
																								DestroyWindow(hwnd);
																								
																								  }
																								  
																									break;
																									
																									  //�����е�С����Ŷ����DestroyWindow������������Ϣ�������к����Ĵ������û�����к����Ĵ�����ܾͻ�������ڲ���ʾ���ǽ��̻��ں�̨���е�����
																									  case WM_DESTROY:
																									  
																										PostQuitMessage(0);
																										
																										  break;
																										  
																											//�����������Ĭ�ϵķ�ʽ��
																											
																											  default:
																											  return DefWindowProc(hwnd,uMsg,wParam,lParam);
																											  }
																											  return 0;
}*/
