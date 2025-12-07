import matplotlib.pyplot as plt

def compute_intersection(p1, p2, e1, e2):
    dx1 = p2[0] - p1[0]
    dy1 = p2[1] - p1[1]
    dx2 = e2[0] - e1[0]
    dy2 = e2[1] - e1[1]
   
    denominator = dx1 * dy2 - dy1 * dx2
    
    if abs(denominator) < 1e-10:
        return None
    
    t = ((e1[0] - p1[0]) * dy2 - (e1[1] - p1[1]) * dx2) / denominator
    
    x = p1[0] + t * dx1
    y = p1[1] + t * dy1
    
    return (x, y)

def is_inside(point, e1, e2):
    cross_product = (e2[0] - e1[0]) * (point[1] - e1[1]) - \
                   (e2[1] - e1[1]) * (point[0] - e1[0])
    return cross_product >= 0

def clip_polygon(polygon, e1, e2):
    clipped = []
    
    for i in range(len(polygon)):
        current = polygon[i]
        previous = polygon[(i-1) % len(polygon)]
        
        current_inside = is_inside(current, e1, e2)
        previous_inside = is_inside(previous, e1, e2)
        
        if previous_inside and current_inside:
            clipped.append(current)
        elif previous_inside and not current_inside:
            intersection = compute_intersection(previous, current, e1, e2)
            if intersection:
                clipped.append(intersection)
        elif not previous_inside and current_inside:
            intersection = compute_intersection(previous, current, e1, e2)
            if intersection:
                clipped.append(intersection)
            clipped.append(current)
    
    return clipped

def runSutherlandHogman(poly, shape):
    working_poly = poly.copy()
   
    for i in range(len(shape)):
        e1 = shape[i]
        e2 = shape[(i+1) % len(shape)]
        working_poly = clip_polygon(working_poly, e1, e2)
        if not working_poly: 
            break
    
    return working_poly


clip_window = [(1, 1), (7, 1), (7, 7), (1, 7)] 
subject_polygon = [(2, 2), (9, 4), (4, 9)] 

result_polygon = runSutherlandHogman(subject_polygon, clip_window)

fig, ax = plt.subplots(figsize=(10, 8))

polygon = plt.Polygon(subject_polygon, alpha=0.3, color='blue', label='Исходный многоугольник')
ax.add_patch(polygon)

clip_patch = plt.Polygon(clip_window, alpha=0.2, color='red', label='Окно отсечения')
ax.add_patch(clip_patch)

if result_polygon:
    result_patch = plt.Polygon(result_polygon, alpha=0.5, color='green', 
                              label='Результат отсечения')
    ax.add_patch(result_patch)

ax.set_xlim(0, 10)
ax.set_ylim(0, 10)
ax.set_aspect('equal')
ax.grid(True, linestyle='--', alpha=0.7)
ax.legend()
ax.set_title('Алгоритм Сазерленда-Ходгмана\nОтсечение многоугольника')

for i, (x, y) in enumerate(subject_polygon):
    ax.annotate(f'P{i}', (x, y), xytext=(5, 5), textcoords='offset points')
    
for i, (x, y) in enumerate(clip_window):
    ax.annotate(f'C{i}', (x, y), xytext=(5, 5), textcoords='offset points')

plt.tight_layout()
plt.show()