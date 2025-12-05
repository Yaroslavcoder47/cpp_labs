import cv2
import numpy as np


CANVAS_SIZE = 600
BACKGROUND_COLOR = (255, 255, 255)
BOUNDARY_COLOR = (0, 0, 0)        
FILL_COLOR = (128, 224, 237)           

img = np.full((CANVAS_SIZE, CANVAS_SIZE, 3), BACKGROUND_COLOR, dtype=np.uint8) 

def draw_boundary():
    """Рисует сложную фигуру (звезду) с черными границами."""
    points = np.array([
        [300, 50], [350, 250], [550, 250], [400, 350], [500, 550], 
        [300, 450], [100, 550], [200, 350], [50, 250], [250, 250]
    ], np.int32)
    
   
    points = points.reshape((-1, 1, 2))
    
    cv2.polylines(img, [points], isClosed=True, color=BOUNDARY_COLOR, thickness=3)
    

    cv2.circle(img, (300, 300), 20, BOUNDARY_COLOR, 2)

def mouse_callback(event, x, y, flags, param):
    """Обрабатывает клик мыши и запускает заливку."""
    if event == cv2.EVENT_LBUTTONDOWN:
        print(f"Запуск заливки в точке: {x}, {y}")
        flood_filling(x, y, FILL_COLOR)
        cv2.imshow("Flood Filling Demo", img)

def flood_filling(start_x, start_y, new_color):
    """Применяет алгоритм затравочного заполнения (Boundary Fill)"""
    mask = np.zeros((CANVAS_SIZE + 2, CANVAS_SIZE + 2), np.uint8)

    low_diff = 10
    up_diff = 10
    
    flags = 4 | cv2.FLOODFILL_FIXED_RANGE 
    
    cv2.floodFill(
        img, 
        mask, 
        (start_x, start_y),      
        new_color,               
        (low_diff, low_diff, low_diff), 
        (up_diff, up_diff, up_diff),    
        flags                    
    )

if __name__ == "__main__":
    draw_boundary()

    cv2.imshow("Flood Filling Demo", img)
    cv2.setMouseCallback("Flood Filling Demo", mouse_callback)

    cv2.waitKey(0) 
    cv2.destroyAllWindows()