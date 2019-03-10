import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
from pylab import savefig




actual_resolution = 'data/actual_resolution.txt'

max_resolution = 'data/max_resolution.txt'



def generate_heatmap(mat, i):
    print(mat)
    heat_map = sns.heatmap(mat, annot=True)
    figure = heat_map.get_figure()
    figure.savefig('heat_map%s.png' % i)
    plt.show()


def output_images(fname, m, n):
    fp = open(fname, 'r')
    for i, line in enumerate(fp):
        line = line.strip()
        start = 0
        end = n
        mat_rep = list()
        for j in range(m):
            a = list()
            for x in line[start:end]:
                a.append(int(x))
            mat_rep.append(a)
            start += n
            end += n
        np_mat_rep = np.array(mat_rep)
        generate_heatmap(np_mat_rep, i)
    
    
    fp.close()





if __name__ == "__main__":
    # output_images(actual_resolution, 6, 8)
    output_images(max_resolution, 42,48)

    