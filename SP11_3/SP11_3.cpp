#include <iostream>
#include <windows.h>
#include <locale.h>
using namespace std;

typedef int (*AddFunc)(int, int);

int main()
{
    setlocale(LC_ALL, "Russian");
    const char* dllName = "SP11_1.dll";
    HMODULE hLib = LoadLibraryA(dllName);
    if (hLib == NULL)
    {
        cerr << "Ошибка: не удалось загрузить " << dllName << endl;
        cerr << "Код ошибки: " << GetLastError() << endl;
        cerr << "Убедитесь, что DLL находится в папке с .exe или в системной папке." << endl;
        return 1;
    }
    AddFunc add = (AddFunc)GetProcAddress(hLib, "Add");
    if (add == NULL)
    {
        cerr << "Ошибка: функция 'Add' не найдена в " << dllName << endl;
        FreeLibrary(hLib);
        return 1;
    }
    int result = add(5, 7);
    cout << "Успешно! Add(5, 7) = " << result << endl;
    FreeLibrary(hLib);
    return 0;
}