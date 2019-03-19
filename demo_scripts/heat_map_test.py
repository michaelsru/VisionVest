import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
from pylab import savefig
import time




actual_resolution = 'data/final_video/act_res.txt'

max_resolution = 'data/final_video/max_res.txt'



def generate_heatmap(mat, i):
    heat_map = sns.heatmap(mat, annot=True)
    figure = heat_map.get_figure()
    figure.savefig('heat_map%s.png' % i)
    plt.clf()


def output_images(fname, m, n):
    fp = open(fname, 'r')
    lines_list = fp.readlines()
    fp.close()
    lines_list = lines_list[::-1]
    len_lines = len(lines_list)
    for i, line in enumerate(lines_list):
        if i < 10:
            continue
        line = line.strip()
        start = 0
        end = n
        mat_rep = list()
        for j in range(m):
            a = list()
            for x in line[start:end]:
                a.append(int(x))
            mat_rep.append(a)
            start += 8 # n or 8 for actual
            end += 8 # n or 8 for actual
        np_mat_rep = np.array(mat_rep)
        np_mat_rep = np.flipud(np_mat_rep)
        np_mat_rep = np.fliplr(np_mat_rep)
        print('matrix is' , np_mat_rep)
        print('i is', i)
        generate_heatmap(np_mat_rep, len_lines - i)
        
    
    
    fp.close()





if __name__ == "__main__":
    output_images(actual_resolution, 6, 8)
    # output_images(max_resolution, 42,48)

    