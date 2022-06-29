#include <stdio.h>

int main(void) {
   int key;
   char inputPath[1024], outPath[1024];
   FILE *inputFile, *outFile;
   int tmp;
   long done = 0, fileSize;
   printf("请输入文件路径：\n");
   scanf("%s", inputPath);
   printf("请输入新文件路径：\n");
   scanf("%s", outPath);
   printf("请输入密匙：\n");
   scanf("%d", &key);
   inputFile = fopen(inputPath, "rb");
   fseek(inputFile, 0, SEEK_END);
   fileSize = ftell(inputFile);
   fseek(inputFile, 0, SEEK_SET);
   outFile = fopen(outPath, "wb");
   printf("已完成：");
   fflush(stdout);
   printf("\033[1m");
   printf("  0.00%%");
   fflush(stdout);
   while (fread(&tmp, 1, 1, inputFile) > 0) {
      tmp ^= key;
      fwrite(&tmp, 1, 1, outFile);
      printf("\b\b\b\b\b\b\b");
      printf("%6.2f%%", (float)done / fileSize * 100);
      fflush(stdout);
      done++;
   }
   printf("\b\b\b\b\b\b\b");
   printf("100.00%%");
   fflush(stdout);
   printf("\033[0m");
   printf("\n");
   printf("文件转换成功\n");
   return 0;
}