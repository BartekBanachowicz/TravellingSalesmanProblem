import math
import sys

from bokeh.io import output_file, show
from bokeh.models import Ellipse, GraphRenderer, StaticLayoutProvider
from bokeh.palettes import Spectral8
from bokeh.plotting import figure

with open(sys.argv[1], 'rt') as nodes:
    print("%s: Node file open\n" %sys.argv[1])
    
    numberOfNodes = int(nodes.readline())
    id = list()
    x = list()
    y = list()

    for i in range(1,numberOfNodes+1):
        tempID, tempX, tempY = nodes.readline().split()
        id.append(int(tempID))
        x.append(float(tempX))
        y.append(float(tempY))


with open(sys.argv[2], 'rt') as edges:
    print("%s: Edges file open\n" %sys.argv[2])
    
    xStart = list()
    xEnd = list()

    for i in range(0,numberOfNodes):
        tempStart, tempEnd = edges.readline().split()
        xStart.append(int(tempStart))
        xEnd.append(int(tempEnd))

#N = 8
#node_indices = list(range(N))

maxX = max(x)
minX = min(x)
maxY = max(y)
minY = min(y)

plot = figure(plot_width=1900, plot_height=900, title='Cykl Hamiltona w grafie', x_range=(minX*0.4,maxX*1.05), y_range=(minY*0.4,maxY*1.05),
              tools='', toolbar_location=None)

graph = GraphRenderer()

graph.node_renderer.data_source.add(id, 'index')
graph.node_renderer.glyph = Ellipse(height=(maxY-minY)/100, width=(maxX-minX)/200, fill_color='lightblue')

graph.edge_renderer.data_source.data = dict(start = xStart, end = xEnd)

graph_layout = dict(zip(id, zip(x, y)))
graph.layout_provider = StaticLayoutProvider(graph_layout=graph_layout)

plot.renderers.append(graph)

output_file('graph.html')
show(plot)