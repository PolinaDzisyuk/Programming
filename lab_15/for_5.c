#include <stdio.h>
#include <string.h>

struct employee {
    char name[128];
    char id[128];
    char level[128];
    int found;
};

struct employee list[1000];

void compress(FILE *in, FILE *out) {
    int cur, next;
    unsigned char cnt;
    cur = fgetc(in);
    while(cur != EOF) {
        cnt = 1;
        while((next=fgetc(in)) != EOF && (next == cur) && cnt < 255) {
            cnt++;
        }
        fputc(cnt, out);
        fputc(cur, out);
        cur = next;
    }   
}

void decompress(FILE *out, FILE *out_after) {
    int cnt, value;
    rewind(out);
    while((cnt=fgetc(out)) != EOF) {
        value = fgetc(out);
        if (value == EOF) {
            break;
        }
        for(int i = 0; i < cnt; i++) {
            fputc(value, out_after);
        }
    }    
}

void print_res(FILE *in, FILE *out) {
    rewind(in);
    fseek(in, 0, SEEK_END);
    long size_in = ftell(in);
    float size_befor = size_in / 1024.0;

    rewind(out);
    fseek(out, 0, SEEK_END);
    long size_out = ftell(out);
    float size_after = size_out  / 1024.0;

    float per_comp = (1.0 - (size_after / size_befor)) * 100;

    printf("Размер до: %f Кб\nРазмер после: %f Кб\nСжатие: %f%\n", size_befor, size_after, per_comp);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Too few arguments:: %s <db_file> <out> <out_after_compress>", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "rb");
    if (in == NULL) {
        printf("Не удалось открыть файл для чтения\n");
        return 1;
    }
    FILE *out = fopen(argv[2], "wb+");
    if (out == NULL) {
        printf("Не удалось открыть файл для записи\n");
        return 1;
    }

    FILE *out_after = fopen(argv[3], "wb");
    if (out == NULL) {
        printf("Не удалось открыть файл для записи\n");
        return 1;
    }
    
    compress(in, out);
    decompress(out, out_after);
    print_res(in, out);

    fclose(in);
    fclose(out);
    fclose(out_after);
}