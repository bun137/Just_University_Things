


'use client';
import { useState, useEffect } from 'react';

const products = [
  {
    name: 'Dell Vostro 15 7500',
    description: '10th Generation Intel Core i7-11390H Processor Arco Linux Hyprland WM',
    price: '82,000',
    quantity: 0
  },
  {
    name: 'MacBook Air M1',
    description: '13.5 Inch, M1 Processor 8 Core CPU, 8 Core GPU, 8GB RAM, 256GB SSD, Space Grey, 2020',
    price: '76,000',
    quantity: 0
  },
  {
    name: 'Dell Latitude 6650',
    description: 'Really old military grade laptop',
    price: '50,000',
    quantity: 0
  }
];

const currentDate = new Date().toLocaleDateString('en-GB');
const expectedDeliveryDate = new Date(new Date().setDate(new Date().getDate() + 3)).toLocaleDateString('en-GB');

const Page = () => {
  const [order, setOrder] = useState({
    products: products,
    totalCost: 0
  });

  useEffect(() => {
    let totalCost = 0;
    order.products.forEach(product => {
      totalCost += product.price * product.quantity;
      console.log(totalCost);
    });
    setOrder(prevOrder => ({ ...prevOrder, totalCost }));
  }, [order.products]);

  const handleQuantityChange = (index, change) => {
    setOrder(prevOrder => {
      const newProducts = [...prevOrder.products];
      newProducts[index].quantity += change;
      return { ...prevOrder, products: newProducts };
    });
  };

  return (
    <div style={style.container}>
      <table style={style.table}>
        <thead>
          <tr>
            <th style={style.th}>Product Name</th>
            <th style={style.th}>Product Description</th>
            <th style={style.th}>Price</th>
            <th style={style.th}>Quantity</th>
          </tr>
        </thead>
        <tbody>
          {order.products.map((product, index) => (
            <tr key={index}>
              <td style={style.td}>{product.name}</td>
              <td style={style.td}>{product.description}</td>
              <td style={style.td}>{product.price}</td>
              <td style={style.td}>
                <button style={style.button} onClick={() => handleQuantityChange(index, -1)}>-</button>
                {product.quantity}
                <button style={style.button} onClick={() => handleQuantityChange(index, 1)}>+</button>
              </td>
            </tr>
          ))}
        </tbody>
      </table>
      <div>
        <p>Order Date: {currentDate}</p>
        <p>Expected Delivery Date: {expectedDeliveryDate}</p>
        <p>Total Cost: 0</p>
      </div>
    </div>
  );
};

const style = {
  container: {
    display: 'flex',
    flexDirection: 'column',
    alignItems: 'center'
  },
  table: {
    borderCollapse: 'collapse',
    margin: '20px'
  },
  th: {
    border: '1px solid black',
    padding: '10px'
  },
  td: {
    border: '1px solid black',
    padding: '10px',
    textAlign: 'center'
  },
  button: {
    padding: '10px',
    margin: '20px',
    fontSize: '16px'
  }
};

export default Page;
