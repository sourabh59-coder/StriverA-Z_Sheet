SELECT C.name as Customers from Customers C where C.id NOT IN (SELECT C.id from Customers C INNER JOIN Orders O ON C.id=O.customerId);
