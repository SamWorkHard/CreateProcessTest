#include<iostream>
#include<windows.h>
int main(int argc, char*argv[])
{
	STARTUPINFO si = { sizeof(STARTUPINFO) };//�ڲ����ӽ���ʱ���ӽ��̵Ĵ��������Ϣ
	PROCESS_INFORMATION pi;                  //�ӽ��̵�ID/�߳������Ϣ
	DWORD returnCode;//���ڱ����ӳ̽��ķ���ֵ;

	wchar_t commandLine1[] = L"CreateProcessSlave.exe -l";  //���������в���һ
	wchar_t commandLine2[] = L"CreateProcessSlave.exe";     //���������в�����

	BOOL bRet = CreateProcess(              //����ʧ�ܣ�����0�����óɹ����ط�0��
		NULL,                               //һ�㶼�ǿգ�����һ��������������˲���ָ��"cmd.exe",��һ�������в��� "/c otherBatFile")
		commandLine1,                       //�����в���         
		NULL,                               //_In_opt_    LPSECURITY_ATTRIBUTES lpProcessAttributes,
		NULL,                               //_In_opt_    LPSECURITY_ATTRIBUTES lpThreadAttributes,
		FALSE,                              //_In_        BOOL                  bInheritHandles,
		CREATE_NEW_CONSOLE,                 //�µĽ���ʹ���µĴ��ڡ�
		NULL,                               //_In_opt_    LPVOID                lpEnvironment,
		NULL,                               //_In_opt_    LPCTSTR               lpCurrentDirectory,
		&si,                                //_In_        LPSTARTUPINFO         lpStartupInfo,
		&pi);                               //_Out_       LPPROCESS_INFORMATION lpProcessInformation

	if (bRet)
	{
		std::cout << "process is running..." << std::endl;
// 		//�ȴ��ӽ��̽���
// 		WaitForSingleObject(pi.hProcess, -1);
// 		std::cout << "process is finished"  << std::endl;
// 		//��ȡ�ӽ��̵ķ���ֵ
// 		GetExitCodeProcess(pi.hProcess, &returnCode);
// 		std::cout << "process return code:" << returnCode << std::endl;
	}
	else
	{
		std::cout << "Create Process error!"<<std::endl;
		return 0;
	}

	getchar();
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
	return 0;
}