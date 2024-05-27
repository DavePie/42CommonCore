use std::ops::{Add, Index, IndexMut, Sub};

#[macro_export]
macro_rules! vector {
    ($($elem:expr),* $(,)?) => {
        Vector::new([$($elem),*])
    };
}

#[derive(Clone, Copy)]
pub struct Vector<K, const N: usize> {
    elem: [K; N],
}

impl<K: Copy, const N: usize> Vector<K, N> {
    pub fn new(elem: [K; N]) -> Self {
        Vector { elem }
    }

    pub fn len(&self) -> usize {
        self.elem.len()
    }

    pub fn get(&self, index: usize) -> Option<&K> {
        self.elem.get(index)
    }
}

impl<K: Copy, const N: usize> Index<usize> for Vector<K, N> {
    type Output = K;

    fn index(&self, index: usize) -> &Self::Output {
        &self.elem[index]
    }
}

impl<K: Copy, const N: usize> IndexMut<usize> for Vector<K, N> {
    fn index_mut(&mut self, index: usize) -> &mut Self::Output {
        &mut self.elem[index]
    }
}

impl<K: Copy, const N: usize> PartialEq for Vector<K, N>
where
    K: PartialEq,
{
    fn eq(&self, other: &Self) -> bool {
        self.elem == other.elem
    }
}

impl<K: Copy, const N: usize> Add for Vector<K, N>
where
    K: Add<Output = K> + Copy,
{
    type Output = Vector<K, N>;

    fn add(self, other: Vector<K, N>) -> Vector<K, N> {
        Vector::new(std::array::from_fn(|i| self.elem[i] + other.elem[i]))
    }
}

impl<K: Copy, const N: usize> Sub for Vector<K, N>
where
    K: Sub<Output = K> + Copy,
{
    type Output = Vector<K, N>;

    fn sub(self, other: Vector<K, N>) -> Vector<K, N> {
        Vector::new(std::array::from_fn(|i| self.elem[i] - other.elem[i]))
    }
}
