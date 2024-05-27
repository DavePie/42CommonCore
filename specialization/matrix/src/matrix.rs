use std::ops::{Add, Index, IndexMut};

use crate::vector::Vector;

pub struct Matrix<K, const N: usize, const M: usize> {
    cols: Vector<Vector<K, M>, N>,
}

#[macro_export]
macro_rules! matrix {
    ($( $( $x:expr ),* );* $(;)?) => {
        {
            let data = vector![
                $(
                    vector![$( $x ),*]
                ),*
            ];
            Matrix::new(data)
        }
    };
}

impl<K: Copy, const N: usize, const M: usize> Matrix<K, N, M> {
    pub fn new(cols: Vector<Vector<K, M>, N>) -> Self {

        Matrix { cols }
    }

    pub fn num_cols(&self) -> usize {
        M
    }

    pub fn num_rows(&self) -> usize {
        N
    }

    pub fn get(&self, index: usize) -> Vector<K, M> {
        self.cols[index]
    }
}

impl<K: Copy, const N: usize, const M: usize> Index<usize> for Matrix<K, N, M> {
    type Output = Vector<K, M>;

    fn index(&self, index: usize) -> &Self::Output {
        &self.cols[index]
    }
}

impl<K: Copy, const N: usize, const M: usize> IndexMut<usize> for Matrix<K, N, M> {
    fn index_mut(&mut self, index: usize) -> &mut Self::Output {
        &mut self.cols[index]
    }
}


impl<K: Copy, const N: usize, const M: usize> Add for Matrix<K, N, M>
where
    K: Add<Output = K> + Copy,
{
    type Output = Matrix<K, N, M>;

    fn add(self, other: Matrix<K, N, M>) -> Matrix<K, N, M> {
        Matrix::new( Vector::new(std::array::from_fn(|i| self.cols[i] + other.cols[i])))
    }
}