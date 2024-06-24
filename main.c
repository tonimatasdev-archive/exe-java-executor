#include <windows.h>
#include <stdio.h>

int main(void) {
    STARTUPINFO startupInfo;
    PROCESS_INFORMATION processInformation;

    ZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);
    ZeroMemory(&processInformation, sizeof(processInformation));

    const char command[] = "java -jar neutron-1.0.0.jar";

    if (!CreateProcess(NULL, command, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &startupInfo, &processInformation)) {
        printf("CreateProcess error (%lu).\n", GetLastError());
        return 1;
    }

    SetForegroundWindow(processInformation.hProcess);

    WaitForSingleObject(processInformation.hProcess, INFINITE);

    CloseHandle(processInformation.hProcess);
    CloseHandle(processInformation.hThread);

    return 0;
}
