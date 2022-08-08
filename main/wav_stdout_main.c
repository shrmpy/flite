#include "flite.h"


cst_voice *register_cmu_us_kal();
void fgj_wave_copy_riff();

int main(void)
{
    cst_voice *v;
    cst_wave *w;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, stdin)) == -1)
    {
        fprintf(stderr,"Failed stdin read \n");
        exit(1);
    }

    v = register_cmu_us_kal(NULL);
    w = flite_text_to_wave(line, v);
    fgj_wave_copy_riff(w);
    free(line);
}
