import numpy as np
import matplotlib.pyplot as plt


def hermite_basis(t):
    t2 = t * t
    t3 = t2 * t
    
    H0 = 2 * t3 - 3 * t2 + 1  
    H1 = -2 * t3 + 3 * t2     
    H2 = t3 - 2 * t2 + t   
    H3 = t3 - t2             
    
    return H0, H1, H2, H3


def hermite_curve(P0, P1, M0, M1, num_points=100):
    t = np.linspace(0, 1, num_points)
    
    X_curve = np.zeros(num_points)
    Y_curve = np.zeros(num_points)
    
    for i, t_val in enumerate(t):
        H0, H1, H2, H3 = hermite_basis(t_val)
        
        
        X_curve[i] = H0 * P0[0] + H1 * P1[0] + H2 * M0[0] + H3 * M1[0]
        Y_curve[i] = H0 * P0[1] + H1 * P1[1] + H2 * M0[1] + H3 * M1[1]
        
    return X_curve, Y_curve


# Управляющие точки 
P0 = np.array([1, 0])     
P1 = np.array([5, -2])    

# Векторы касательных 
M0 = np.array([2, 4])     
M1 = np.array([1, -4]) 


# --- Построение графика ---

X_curve, Y_curve = hermite_curve(P0, P1, M0, M1)

plt.figure(figsize=(10, 8)) 
plt.scatter([P0[0], P1[0]], [P0[1], P1[1]], 
            color='blue', 
            label='Управляющие точки (P0, P1)', 
            s=100, zorder=5)

plt.plot(X_curve, Y_curve, 
         color='tab:orange', 
         label='Кривая Эрмита', 
         linewidth=2)

plt.quiver(P0[0], P0[1], M0[0], M0[1], 
           angles='xy', scale_units='xy', scale=1, 
           color='red', width=0.005, label='Касательная M0')
plt.quiver(P1[0], P1[1], M1[0], M1[1], 
           angles='xy', scale_units='xy', scale=1, 
           color='green', width=0.005, label='Касательная M1')



plt.title('Аппроксимация Кубической Кривой Эрмита', fontsize=16)
plt.xlabel('X', fontsize=12)
plt.ylabel('Y', fontsize=12)
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()
plt.xlim(0, 9) 
plt.ylim(-7, 5) 

plt.show()

# Кривая Эрмита
# P(t) = H_0(t)*P_0 + H_1(t)*P_1 + H_2(t)*M_0 + H_3(t)*M_1
# H_i(t) - Базисные функции Эрмита 
# H_0(t) = 2t^3 - 3t^2 + 1
# H_1(t) = -2t^3 + 3t^2
# H_2(t) = t^3 - 2t^2 + t
# H_3(t) = t^3 - t^2
