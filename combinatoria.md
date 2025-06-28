Perfecto. Aquí tienes una **hoja extremadamente resumida de combinatoria para competencias de programación**, en formato Markdown, con **fórmulas y cuándo usarlas**.

---

# 🧠 Hoja Rápida de Combinatoria – CP/ICPC

> 📌 **Usa esta hoja para identificar la fórmula correcta según el tipo de problema.**

---

## 🔹 1. Subconjuntos (sin orden)

### 🎯 ¿Cuántos subconjuntos se pueden formar con n elementos?

**Fórmula:**

```
2^n
```

---

## 🔹 2. Permutaciones (con orden, sin repetición)

### 🎯 ¿De cuántas formas se pueden ordenar k elementos de n?

**Fórmula:**

```
P(n, k) = n! / (n - k)!
```

---

## 🔹 3. Permutaciones con repetición

### 🎯 ¿De cuántas formas se pueden ordenar n elementos, algunos repetidos?

**Fórmula:**

```
n! / (k1! * k2! * ... * kr!)
```

> Donde `k1, k2, ..., kr` son las repeticiones de elementos idénticos.

---

## 🔹 4. Combinaciones (sin orden, sin repetición)

### 🎯 ¿Cuántos grupos de k elementos se pueden formar a partir de n?

**Fórmula:**

```
C(n, k) = n! / (k! * (n - k)!)
```

---

## 🔹 5. Combinaciones con repetición

### 🎯 ¿Cuántas formas hay de elegir k elementos de n tipos, permitiendo repetir?

**Fórmula:**

```
C(n + k - 1, k)
```

---

## 🔹 6. Distribuir k objetos idénticos en n cajas (vacías permitidas)

### 🎯 ¿Cuántas formas de distribuir k bolas idénticas en n cajas?

**Fórmula:**

```
C(n + k - 1, k)
```

---

## 🔹 7. Distribuir k objetos idénticos en n cajas (sin vacías)

### 🎯 ¿Y si ninguna caja puede quedar vacía?

**Fórmula:**

```
C(k - 1, n - 1)
```

---

## 🔹 8. Particiones de un número

### 🎯 ¿Cuántas formas hay de escribir `n` como suma de enteros positivos?

**Fórmula:**
No cerrada; usar **DP**

```cpp
dp[n+1][n+1] = {0};
dp[0][0] = 1;
for (int i = 1; i <= n; i++)
    for (int j = 0; j <= n; j++)
        for (int k = 0; k + i <= n; k++)
            dp[i][j + i] += dp[i - 1][j];
```

---

## 🔹 9. Número de subconjuntos de tamaño k

### 🎯 ¿Cuántos subconjuntos exactamente de k elementos?

**Fórmula:**

```
C(n, k)
```

---

## 🔹 10. Binomio de Newton

### 🎯 ¿Coeficientes de expansión de (a + b)^n?

**Fórmula:**

```
(a + b)^n = ∑ C(n, k) * a^(n-k) * b^k
```

---

## 🔹 11. Suma combinatoria

### 🎯 ¿Cuánto vale la suma C(n, 0) + C(n, 1) + ... + C(n, n)?

**Fórmula:**

```
2^n
```

---

## 🔹 12. Permutaciones circulares

### 🎯 ¿Cuántas formas de sentar n personas en una mesa circular?

**Fórmula:**

```
(n - 1)!
```

---

## 🔹 13. Combinatoria con módulo (MOD primo)

### 🎯 C(n, k) % MOD cuando MOD es primo

**Fórmula:**

```cpp
C(n, k) = fact[n] * inv_fact[k] * inv_fact[n-k] % MOD
```

---

## ⚙️ Códigos base para usar:

### Factorial + Inverso modular

```cpp
const int MOD = 1e9+7, N = 1e6;
ll fact[N], inv[N];

ll mod_pow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % MOD;
    inv[N - 1] = mod_pow(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
}

ll C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}
```

---

¿Deseas este documento exportado como archivo `.md` o adaptado para imprimir como hoja de repaso rápida (PDF/A4)?
