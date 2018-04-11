int main(int argc, char const *argv[])
{
    int i, j;
    while(i <= 100) {
        for (int j = 0; j < 5; ++j)
        {
            printf("%i\t", i);
            i++;
        }
        printf("\n");
    }
    return 0;
}