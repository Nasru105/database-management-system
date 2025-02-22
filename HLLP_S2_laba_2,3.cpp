﻿#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>

struct row
{
	char name[20];
	char category[20];
	int quantity;
	char country[20];
	int storage;
};
struct search_in_column
{
	int column;
	char word[20];
};
void column(int n, char(&res)[20])
{
	switch (n)
	{
	case 1:
		strcpy_s(res, "name");
		break;
	case 2:
		strcpy_s(res, "category");
		break;
	case 3:
		strcpy_s(res, "quantity");
		break;
	case 4:
		strcpy_s(res, "country");
		break;
	case 5:
		strcpy_s(res, "storage");
		break;
	}
}
const char* get_column_value(const row& data, int column_index)
{
	switch (column_index)
	{
	case 1:
		return data.name;
	case 2:
		return data.category;
	case 4:
		return data.country;
	}

}
void print_colums(int(&numbers)[5], char(&res)[20], int cnt)
{
	static int k = 1;
	printf("\nselect %d column for search:\n", k++);
	for (int i = 0; i < 5; i++)
	{
		if (numbers[i] == 1)
		{
			cnt++;
			column(i + 1, res);
			printf("%d - %s\n", i + 1, res);
		}
		if (cnt + 1 == k)
		{
			k = 1;
		}
	}
}
int get_integer_column_value(const row& data, int column_index)
{
	switch (column_index)
	{
	case 3:
		return data.quantity;
	case 5:
		return data.storage;
	}
}
void database_input_keyboard(int& len, row(&database)[400])
{
	len = 0;
	printf("\nEnter data in the following format:\n\nstring_name string_category int_quantity string_country int_storage\n");
	while (len < 400)
	{
		printf("\nEnter data for row %d: ", len + 1);
		int result = scanf_s("%s %s %d %s %d",
			database[len].name, sizeof(database[len].name),
			database[len].category, sizeof(database[len].category),
			&database[len].quantity,
			database[len].country, sizeof(database[len].country),
			&database[len].storage);
		if (result == 0)
		{
			break;
		}
		else if (result != 5)
		{
			printf("\nInput error\n");
			len--;
			scanf_s("%*[^\n]");
		}
		len++;
	}
}
void datebase_input_file(int& len, row(&database)[400])
{
	FILE* db;
	len = 0;
	fopen_s(&db, "programs_C++/Texts/database.txt", "r");
	if (db == NULL)
	{
		printf("Ошибка открытия файла.\n");
		return;
	}

	// Читаем значения из файла и добавляем их в массив структур
	while (fscanf_s(db, "%s %s %d %s %d", database[len].name, sizeof(database[len].name),
		database[len].category, sizeof(database[len].category),
		&database[len].quantity,
		database[len].country, sizeof(database[len].country),
		&database[len].storage) != EOF)
	{
		len++;
	}
	fclose(db);
}
void database_add_keyboard(int& len, row(&database)[400])
{
	printf("\nEnter data in the following format:\n\nstring_name string_category int_quantity string_country int_storage\n");
	while (len < 400)
	{
		printf("\nEnter data for row %d: ", len + 1);
		int result = scanf_s("%19s %19s %d %19s %d",
			database[len].name, sizeof(database[len].name),
			database[len].category, sizeof(database[len].category),
			&database[len].quantity,
			database[len].country, sizeof(database[len].country),
			&database[len].storage);
		if (result == 0)
		{
			break;
		}

		len++;
	}
}
void datebase_output_screen(int& len, row database[400])
{
	int k = 0, n = 1, W = 84, w = W / 12;
	// вывод верхней границы
	for (k = 0; k < W; k++)
	{
		if (k == 0)
			printf("%c", 201);
		else if (k == W - 1)
			printf("%c\n", 187);
		else if (k == w || k == 3 * w || k == 6 * w || k == 8 * w || k == 10 * w)
			printf("%c", 203);
		else
			printf("%c", 205);
	}
	// вывод верхней границы
	// шапка
	printf("%c%*s%*c%*s%*c%*s%*c%*s%*c%*s%*c%*s%*c\n", 186, (w / 2 + 1), "No", w - (w / 2 + 1), 186, w + 2, "name", w - 2, 186, (3 * (w / 2)) + 4, "category", 3 * w - ((3 * (w / 2)) + 4), 186, w + 4, "quantity", w - 4, 186, w + 4, "country", w - 4, 186, w + 3, "storage", w - 4, 186);
	// шапка
	// тело
	for (int i = 0; i < (len); i++)
	{
		for (k = 0; k < W; k++)
		{
			if (k == 0)
				printf("%c", 204);
			else if (k == W - 1)
				printf("%c\n", 185);
			else if (k == w || k == 3 * w || k == 6 * w || k == 8 * w || k == 10 * w)
				printf("%c", 206);
			else
				printf("%c", 205);
		}
		printf("%c%*d%*c%*s%*c%*s%*c%*d%*c%*s%*c%*d%*c\n", 186, (w / 2 + 1), n, w - (w / 2 + 1), 186, w + strlen(database->name) / 2, database->name, w - strlen(database->name) / 2, 186, (3 * (w / 2)) + strlen(database->category) / 2, database->category, 3 * w - ((3 * (w / 2)) + strlen(database->category) / 2), 186, w + 1, database->quantity, w - 1, 186, w + strlen(database->country) / 2, database->country, w - strlen(database->country) / 2, 186, w, database->storage, w - 1, 186);
		n++;
		database++;
	}
	// тело
	// вывод нижней границы
	for (k = 0; k < W; k++)
	{
		if (k == 0)
			printf("%c", 200);
		else if (k == W - 1)
			printf("%c\n", 188);
		else if (k == w || k == 3 * w || k == 6 * w || k == 8 * w || k == 10 * w)
			printf("%c", 202);
		else
			printf("%c", 205);
	}
	// вывод нижней границы
}
void datebase_output_file(int& len, row(&database)[400])
{
	FILE* db;
	fopen_s(&db, "Texts/database.txt", "w");
	if (db == NULL)
	{
		printf("Ошибка открытия файла.\n");
		return;
	}
	for (int i = 0; i < len; i++)
	{
		fprintf(db, "%s %s %d %s %d\n", database[i].name, database[i].category, database[i].quantity, database[i].country, database[i].storage);
	}
	fclose(db);
}
void database_delete(int& len, row(&database)[400])
{
	int cnt, numbers[] = { 1, 1, 1, 1, 1 }, actl[] = { 0, 0 };
	char res[20];
	int k = 0, n = 1, W = 60, w = W / 12, act;
	row search_database[400];
	search_in_column search[5] = { {0, ""}, {0, ""}, {0, ""}, {0, ""}, {0, ""} };

	// вывод верхней границы
	for (k = 0; k < W; k++)
	{
		if (k == 0)
			printf("%c", 201);
		else if (k == W - 1)
			printf("%c\n", 187);
		else if (k == 2 * w || k == 5 * w || k == 7 * w || k == 9 * w)
			printf("%c", 203);
		else
			printf("%c", 205);
	}
	// шапка
	printf("%c%*s%*c%*s%*c%*s%*c%*s%*c%*s%*c\n", 186, w + 1, "name", w - 1, 186, (3 * (w / 2)) + 5, "category", 3 * w - ((3 * (w / 2)) + 5), 186, w + 4, "quantity", w - 4, 186, w + 3, "country", w - 3, 186, w + 5, "storage", w - 1, 186);
	// вывод нижней границы
	for (k = 0; k < W; k++)
	{
		if (k == 0)
			printf("%c", 200);
		else if (k == W - 1)
			printf("%c\n", 188);
		else if (k == 2 * w || k == 5 * w || k == 7 * w || k == 9 * w)
			printf("%c", 202);
		else
			printf("%c", 205);
	}

	printf("\nselect number of columns - ");
	scanf_s("%d", &cnt);
	while ((cnt < 1) || (cnt > 5))
	{
		scanf_s("%*[^\n]");
		printf("\nselect number 1-5\n");
		scanf_s("%d", &cnt);
	}
	for (int i = 0; i < cnt; i++)
	{
		print_colums(numbers, res, cnt);
		scanf_s("%d", &search[i].column);
		while ((search[i].column < 1) || (search[i].column > 5) || (numbers[search[i].column - 1] == 0))
		{
			scanf_s("%*[^\n]");
			printf("\nselect number 1-5\n");
			scanf_s("%d", &search[i].column);
		}
		numbers[search[i].column - 1] = 0;
		column(search[i].column, res);
		if (search[i].column == 3 || search[i].column == 5)
		{
			printf("\nselect action\n1 - equals (=)\n2 - more (>)\n3 - less (<)\n");
			scanf_s("%d", &act);
			while ((act < 1) || (act > 3))
			{
				scanf_s("%*[^\n]");
				printf("\nselect number 1-3\n");
				scanf_s("%d", &act);
			}
			if (search[i].column == 3)
				actl[0] = act;
			else
				actl[1] = act;
			switch (act)
			{
			case 1:
			{
				printf("\ndelete in %s equals to: ", res);
				scanf_s("%s", search[i].word, sizeof(search[i].word));
				char* endptr;
				long number = strtol(search[i].word, &endptr, 10);
				while ((endptr == search[i].word) || (*endptr != '\0'))
				{
					scanf_s("%*[^\n]");
					printf("\nenter an integer: ", res);
					scanf_s("%s", search[i].word, sizeof(search[i].word));
					long number = strtol(search[i].word, &endptr, 10);
				}
				break;
			}
			case 2:
			{
				printf("\ndelete in %s more than: ", res);
				scanf_s("%s", search[i].word, sizeof(search[i].word));
				char* endptr;
				long number = strtol(search[i].word, &endptr, 10);
				while ((endptr == search[i].word) || (*endptr != '\0'))
				{
					scanf_s("%*[^\n]");
					printf("\nenter an integer: ", res);
					scanf_s("%s", search[i].word, sizeof(search[i].word));
					long number = strtol(search[i].word, &endptr, 10);
				}
				break;
			}
			case 3:
			{
				printf("\ndelete in %s less than: ", res);
				scanf_s("%s", search[i].word, sizeof(search[i].word));
				char* endptr;
				long number = strtol(search[i].word, &endptr, 10);
				while ((endptr == search[i].word) || (*endptr != '\0'))
				{
					scanf_s("%*[^\n]");
					printf("\nenter an integer: ", res);
					scanf_s("%s", search[i].word, sizeof(search[i].word));
					long number = strtol(search[i].word, &endptr, 10);
				}
				break;
			}
			}
		}
		else
		{
			printf("\nword for delete in% s: ", res);
			scanf_s("%s", search[i].word, sizeof(search[i].word));
		}
	}
	k = 0;
	int cnt_res = 0, cnt_test = 0;
	for (int j = 0; j < 5; j++)
	{
		if (search[j].column != 0)
		{
			cnt_res++;
		}
	}
	for (int i = 0; i < len; i++)
	{
		cnt_test = 0;
		for (int j = 0; j < 5; j++)
		{
			if (search[j].column != 0)
			{
				switch (search[j].column)
				{
					{
				case 1:
				{
					if (!strcmp((search[j].word), (database[i].name)))
						cnt_test++;
				}
				break;
					}
				case 2:
				{
					if (!strcmp((search[j].word), (database[i].category)))
					{
						cnt_test++;
					}
					break;
				}
				case 3:
				{
					char str[20];
					sprintf_s(str, "%d", database[i].quantity);
					if (actl[0] == 1)
					{
						if (!strcmp((search[j].word), (str)))
						{
							cnt_test++;
						}
					}
					else if (actl[0] == 2)
					{
						if ((atoi(search[j].word)) < (database[i].quantity))
							cnt_test++;
					}
					else
					{
						if ((atoi(search[j].word)) > (database[i].quantity))
							cnt_test++;
					}
					break;
				}
				case 4:
				{
					if (!strcmp((search[j].word), (database[i].country)))
					{
						cnt_test++;
					}
					break;
				}
				case 5:
				{
					char str[20];
					sprintf_s(str, "%d", database[i].storage);
					if (actl[1] == 1)
					{
						if (!strcmp((search[j].word), (str)))
						{
							cnt_test++;
						}
					}
					else if (actl[1] == 2)
					{
						if ((atoi(search[j].word)) < (database[i].storage))
							cnt_test++;
					}
					else
					{
						if ((atoi(search[j].word)) > (database[i].storage))
							cnt_test++;
					}
					break;
				}
				}
			}
		}
		if (!(cnt_res == cnt_test))
		{
			search_database[k] = database[i];
			k++;
		}
	}
	len = k;
	for (int i = 0; i < len; i++)
	{
		database[i] = search_database[i];
	}
	datebase_output_screen(len, database);
}
void database_search(int& len, row(&database)[400])
{
	int cnt, numbers[] = { 1, 1, 1, 1, 1 }, actl[] = { 0, 0 };
	char res[20];
	int k = 0, n = 1, W = 60, w = W / 12, act;
	row search_database[400];
	search_in_column search[5] = { {0, ""}, {0, ""}, {0, ""}, {0, ""}, {0, ""} };

	// вывод верхней границы
	for (k = 0; k < W; k++)
	{
		if (k == 0)
			printf("%c", 201);
		else if (k == W - 1)
			printf("%c\n", 187);
		else if (k == 2 * w || k == 5 * w || k == 7 * w || k == 9 * w)
			printf("%c", 203);
		else
			printf("%c", 205);
	}
	// шапка
	printf("%c%*s%*c%*s%*c%*s%*c%*s%*c%*s%*c\n", 186, w + 1, "name", w - 1, 186, (3 * (w / 2)) + 5, "category", 3 * w - ((3 * (w / 2)) + 5), 186, w + 4, "quantity", w - 4, 186, w + 3, "country", w - 3, 186, w + 5, "storage", w - 1, 186);
	// вывод нижней границы
	for (k = 0; k < W; k++)
	{
		if (k == 0)
			printf("%c", 200);
		else if (k == W - 1)
			printf("%c\n", 188);
		else if (k == 2 * w || k == 5 * w || k == 7 * w || k == 9 * w)
			printf("%c", 202);
		else
			printf("%c", 205);
	}

	printf("\nselect number of columns - ");
	scanf_s("%d", &cnt);
	while ((cnt < 1) || (cnt > 5))
	{
		scanf_s("%*[^\n]");
		printf("\nselect number 1-5\n");
		scanf_s("%d", &cnt);
	}
	for (int i = 0; i < cnt; i++)
	{
		print_colums(numbers, res, cnt);
		scanf_s("%d", &search[i].column);
		while ((search[i].column < 1) || (search[i].column > 5) || (numbers[search[i].column - 1] == 0))
		{
			scanf_s("%*[^\n]");
			printf("\nselect number 1-5\n");
			scanf_s("%d", &search[i].column);
		}
		numbers[search[i].column - 1] = 0;
		column(search[i].column, res);
		if (search[i].column == 3 || search[i].column == 5)
		{
			printf("\nselect action\n1 - equals (=)\n2 - more (>)\n3 - less (<)\n");
			scanf_s("%d", &act);
			while ((act < 1) || (act > 3))
			{
				scanf_s("%*[^\n]");
				printf("\nselect number 1-3\n");
				scanf_s("%d", &act);
			}
			if (search[i].column == 3)
				actl[0] = act;
			else
				actl[1] = act;
			switch (act)
			{
			case 1:
			{
				printf("\nsearch in %s equals to: ", res);
				scanf_s("%s", search[i].word, sizeof(search[i].word));
				char* endptr;
				long number = strtol(search[i].word, &endptr, 10);
				while ((endptr == search[i].word) || (*endptr != '\0'))
				{
					scanf_s("%*[^\n]");
					printf("\nenter an integer: ", res);
					scanf_s("%s", search[i].word, sizeof(search[i].word));
					long number = strtol(search[i].word, &endptr, 10);
				}
				break;
			}
			case 2:
			{
				printf("\nsearch in %s more than: ", res);
				scanf_s("%s", search[i].word, sizeof(search[i].word));
				char* endptr;
				long number = strtol(search[i].word, &endptr, 10);
				while ((endptr == search[i].word) || (*endptr != '\0'))
				{
					scanf_s("%*[^\n]");
					printf("\nenter an integer: ", res);
					scanf_s("%s", search[i].word, sizeof(search[i].word));
					long number = strtol(search[i].word, &endptr, 10);
				}
				break;
			}
			case 3:
			{
				printf("\nsearch in %s less than: ", res);
				scanf_s("%s", search[i].word, sizeof(search[i].word));
				char* endptr;
				long number = strtol(search[i].word, &endptr, 10);
				while ((endptr == search[i].word) || (*endptr != '\0'))
				{
					scanf_s("%*[^\n]");
					printf("\nenter an integer: ", res);
					scanf_s("%s", search[i].word, sizeof(search[i].word));
					long number = strtol(search[i].word, &endptr, 10);
				}
				break;
			}
			}
		}
		else
		{
			printf("\nsearch in %s: ", res);
			scanf_s("%s", search[i].word, sizeof(search[i].word));
		}
	}
	k = 0;
	int cnt_res = 0, cnt_test = 0;
	for (int j = 0; j < 5; j++)
	{
		if (search[j].column != 0)
		{
			cnt_res++;
		}
	}
	for (int i = 0; i < len; i++)
	{
		cnt_test = 0;
		for (int j = 0; j < 5; j++)
		{
			if (search[j].column != 0)
			{
				switch (search[j].column)
				{
					{
				case 1:
				{
					if (!strcmp((search[j].word), (database[i].name)))
						cnt_test++;
				}
				break;
					}
				case 2:
				{
					if (!strcmp((search[j].word), (database[i].category)))
					{
						cnt_test++;
					}
					break;
				}
				case 3:
				{
					char str[20];
					sprintf_s(str, "%d", database[i].quantity);
					if (actl[0] == 1)
					{
						if (!strcmp((search[j].word), (str)))
						{
							cnt_test++;
						}
					}
					else if (actl[0] == 2)
					{
						if ((atoi(search[j].word)) < (database[i].quantity))
							cnt_test++;
					}
					else
					{
						if ((atoi(search[j].word)) > (database[i].quantity))
							cnt_test++;
					}
					break;
				}
				case 4:
				{
					if (!strcmp((search[j].word), (database[i].country)))
					{
						cnt_test++;
					}
					break;
				}
				case 5:
				{
					char str[20];
					sprintf_s(str, "%d", database[i].storage);
					if (actl[1] == 1)
					{
						if (!strcmp((search[j].word), (str)))
						{
							cnt_test++;
						}
					}
					else if (actl[1] == 2)
					{
						if ((atoi(search[j].word)) < (database[i].storage))
							cnt_test++;
					}
					else
					{
						if ((atoi(search[j].word)) > (database[i].storage))
							cnt_test++;
					}
					break;
				}
				}
			}
		}
		if (cnt_res == cnt_test)
		{
			search_database[k] = database[i];
			k++;
		}
	}
	len = k;
	for (int i = 0; i < len; i++)
	{
		database[i] = search_database[i];
	}
	datebase_output_screen(len, database);
}
void database_sort(int& len, row(&database)[400])
{
	int cnt, sort[5][2], numbers[] = { 1, 1, 1, 1, 1 };
	char res[20];
	int k = 0, n = 1, W = 60, w = W / 12;
	row sort_database[400];

	// вывод верхней границы
	for (k = 0; k < W; k++)
	{
		if (k == 0)
			printf("%c", 201);
		else if (k == W - 1)
			printf("%c\n", 187);
		else if (k == 2 * w || k == 5 * w || k == 7 * w || k == 9 * w)
			printf("%c", 203);
		else
			printf("%c", 205);
	}
	// вывод верхней границы
	// шапка
	printf("%c%*s%*c%*s%*c%*s%*c%*s%*c%*s%*c\n", 186, w + 1, "name", w - 1, 186, (3 * (w / 2)) + 5, "category", 3 * w - ((3 * (w / 2)) + 5), 186, w + 4, "quantity", w - 4, 186, w + 3, "country", w - 3, 186, w + 5, "storage", w - 1, 186);
	// шапка
	// вывод нижней границы
	for (k = 0; k < W; k++)
	{
		if (k == 0)
			printf("%c", 200);
		else if (k == W - 1)
			printf("%c\n", 188);
		else if (k == 2 * w || k == 5 * w || k == 7 * w || k == 9 * w)
			printf("%c", 202);
		else
			printf("%c", 205);
	}
	// вывод нижней границы

	printf("\nselect number of columns - ");
	scanf_s("%d", &cnt);
	while ((cnt < 1) || (cnt > 5))
	{
		scanf_s("%*[^\n]");
		printf("\nselect number 1-5\n");
		scanf_s("%d", &cnt);
	}
	for (int i = 0; i < cnt; i++)
	{
		print_colums(numbers, res, cnt);
		scanf_s("%d", &sort[i][0]); // sort=[[номер столбца, номер сортировки]]
		while ((sort[i][0] < 1) || (sort[i][0] > 5) || (numbers[sort[i][0] - 1] == 0))
		{
			scanf_s("%*[^\n]");
			printf("\nselect number 1-5\n");
			scanf_s("%d", &sort[i][0]);
		}
		numbers[sort[i][0] - 1] = 0;
		column(sort[i][0], res);
		printf("\nsort %s by:\n1 - ascending \n2 - descending\n", res);
		scanf_s("%d", &sort[i][1]);
		while ((sort[i][1] < 1) || (sort[i][1] > 2))
		{
			scanf_s("%*[^\n]");
			printf("\nselect number 1-2\n");
			scanf_s("%d", &sort[i][1]);
		}
	}
	row temp;
	int i, j;
	for (int col = (5 - cnt); col >= 0; col--)
	{
		for (i = 1; i < len; i++)
		{
			temp = database[i];
			j = i - 1;
			if (sort[col][0] == 1 || sort[col][0] == 2 || sort[col][0] == 4)
			{
				while (j >= 0 && (sort[col][1] == 1 ? strcmp(get_column_value(database[j], sort[col][0]), get_column_value(temp, sort[col][0])) > 0 : strcmp(get_column_value(database[j], sort[col][0]), get_column_value(temp, sort[col][0])) < 0))
				{
					database[j + 1] = database[j];
					j--;
				}
				database[j + 1] = temp;
			}
			else
			{
				while (j >= 0 && (sort[col][1] == 1 ? get_integer_column_value(database[j], sort[col][0]) > get_integer_column_value(temp, sort[col][0]) : get_integer_column_value(database[j], sort[col][0]) < get_integer_column_value(temp, sort[col][0])))
				{
					database[j + 1] = database[j];
					j--;
				}
				database[j + 1] = temp;
			}
		}
	}
	datebase_output_screen(len, database);
}

int main()
{
	int len = 0, act = 0;
	row database[400];
	FILE* db;

	datebase_output_screen(len, database);
	while (act != 7)
	{
		printf("\nselect action number:\n1 - input\n2 - output\n3 - add\n4 - search\n5 - delete\n6 - sort\n7 - exit\n");
		scanf_s("%d", &act);
		while ((act < 1) || (act > 7))
		{
			scanf_s("%*[^\n]");
			printf("\nselect action 1-7\n");
			scanf_s("%d", &act);
		}
		switch (act)
		{
		case 1:
		{
			printf("\nselect action number:\n1 - from the keyboard\n2 - from file\n");
			scanf_s("%d", &act);
			while ((act < 1) || (act > 2))
			{
				scanf_s("%*[^\n]");
				printf("\nselect action 1-2\n");
				scanf_s("%d", &act);
			}
			switch (act)
			{
			case 1:
			{
				database_input_keyboard(len, database);
				break;
			}
			case 2:
			{
				datebase_input_file(len, database);
				break;
			}
			}
			break;
		}
		case 2:
		{
			printf("\nselect action number:\n1 - to screen\n2 - to file\n");
			scanf_s("%d", &act);
			while ((act < 1) || (act > 2))
			{
				scanf_s("%*[^\n]");
				printf("\nselect action 1-2\n");
				scanf_s("%d", &act);
			}
			switch (act)
			{
			case 1:
			{
				datebase_output_screen(len, database);
				break;
			}
			case 2:
			{
				datebase_output_file(len, database);
				break;
			}
			}
			break;
		}
		case 3:
		{
			database_add_keyboard(len, database);
			break;
		}
		case 4:
		{
			database_search(len, database);
			break;
		}
		case 5:
		{
			database_delete(len, database);
			break;
		}
		case 6:
		{
			database_sort(len, database);
			break;
		}
		}
	}
	return 0;
}