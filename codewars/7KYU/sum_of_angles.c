/* Find the total sum of internal angles (in degrees) in an n-sided simple polygon. N will be greater than 2. */
int angle(int n) {
  return (n - 2) * 180;
}

/* 
### Explanation:
- A polygon can be divided into \((n - 2)\) triangles, where \( n \) is the number of sides.
- Each triangle has a sum of internal angles equal to \( 180^\circ \).
- Multiplying \((n - 2)\) by \( 180^\circ \) gives the total sum of the internal angles.

### Example:
1. **Triangle (\( n = 3 \)):**
   \[
   \text{Sum} = (3 - 2) \times 180 = 180^\circ
   \]

2. **Quadrilateral (\( n = 4 \)):**
   \[
   \text{Sum} = (4 - 2) \times 180 = 360^\circ
   \]

3. **Pentagon (\( n = 5 \)):**
   \[
   \text{Sum} = (5 - 2) \times 180 = 540^\circ
   \] */
