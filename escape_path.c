#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int main(int argc, char const *argv[])
{
  wchar_t buf[500] = L"C:\\test\\testing\\tester\\test.txt";
  wchar_t buf2[500] = L"";
  wchar_t *p = buf;
  wchar_t *p2;

  while((p2 = wcschr(p,'\\'))!=NULL)
  {
    *p2=L'\0';
    wcscat(buf2,p);
    wcscat(buf2,L"\\\\");
    p=p2+1;
  }
  wcscat(buf2,p);

  wprintf(buf2);
  return 0;
}