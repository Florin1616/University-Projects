using System.Data;
using System.Data.SqlClient;
using System.Collections.Generic;
using System.Data.Common;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace LAB1
{
    public partial class Form1 : Form
    {

        private SqlConnection dbConnection;
        private SqlDataAdapter daCustomerOrders, daShippingDetails;
        private DataSet tableData;
        private DataRelation drCustomerOrdersShippingDetails;
        BindingSource bsCustomerOrders, bsShippingDetails;


        public Form1()
        {
            InitializeComponent();
            this.Load += new System.EventHandler(this.Form1_Load);


        }

        private void Form1_Load(object sender, EventArgs e)
        {

            dbConnection = new SqlConnection("Data Source=DESKTOP-99TL53K\\SQLEXPRESS;Initial Catalog=CarPartsShop;Integrated Security=True");


            daCustomerOrders = new SqlDataAdapter("SELECT * FROM CustomerOrders", dbConnection);
            tableData = new DataSet();
            daCustomerOrders.Fill(tableData, "CustomerOrders");

            daShippingDetails = new SqlDataAdapter("SELECT * FROM ShippingDetails", dbConnection);
            daShippingDetails.Fill(tableData, "ShippingDetails");

            drCustomerOrdersShippingDetails = new DataRelation("CustomerOrders_ShippingDetails", tableData.Tables["CustomerOrders"].Columns["OrderID"],
                                                        tableData.Tables["ShippingDetails"].Columns["OrderID"]);

            tableData.Relations.Add(drCustomerOrdersShippingDetails);

            CustomerOrdersView.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
            bsCustomerOrders = new BindingSource();
            bsCustomerOrders.DataSource = tableData;
            bsCustomerOrders.DataMember = "CustomerOrders";
            CustomerOrdersView.DataSource = bsCustomerOrders;

            ShippingDetailsView.DataSource = bsCustomerOrders;
            ShippingDetailsView.DataMember = "CustomerOrders_ShippingDetails";

            ShippingDetailsView.SelectionChanged += ShippingDetailsView_SelectionChanged;
            CustomerOrdersView.SelectionChanged += CustomerOrdersView_SelectionChanged;

        }




        private void ReloadShippingDetailsTableView()
        {
            if (tableData.Tables["ShippingDetails"] != null)
            {
                tableData.Tables["ShippingDetails"].Clear();
            }
            daShippingDetails.Fill(tableData, "ShippingDetails");

            if (bsShippingDetails != null)
            {
                bsShippingDetails.ResetBindings(false);
            }
        }

        private void ShippingDetailsView_SelectionChanged(object sender, EventArgs e)
        {
            if (ShippingDetailsView.SelectedRows.Count > 0)
            {
                DataGridViewRow selectedRow = ShippingDetailsView.SelectedRows[0];

                shippingIDTextBox.Text = selectedRow.Cells["ShippingID"].Value.ToString();
                orderIDTextBox.Text = selectedRow.Cells["OrderID"].Value.ToString();

            }
        }

        private void CustomerOrdersView_SelectionChanged(object sender, EventArgs e)
        {
            if (CustomerOrdersView.SelectedRows.Count > 0)
            {
                DataGridViewRow selectedRow = CustomerOrdersView.SelectedRows[0];

                OrderID.Text = selectedRow.Cells["OrderID"].Value.ToString();

            }
        }


        private void addButton_Click(object sender, EventArgs e)
        {
            try
            {
                int orderId;
                if (!int.TryParse(OrderID.Text, out orderId))
                {
                    MessageBox.Show("Order ID must be an integer.");
                    return;
                }

                if (!int.TryParse(ShippingID.Text, out int shippingId))
                {
                    MessageBox.Show("Shipping ID must be an integer.");
                    return;
                }

                if (!DateTime.TryParse(ShippingDate.Text, out DateTime shippingDate))
                {
                    MessageBox.Show("Invalid Shipping Date format.");
                    return;
                }

                string shippingStreet = ShippingStreet.Text;
                if (string.IsNullOrWhiteSpace(shippingStreet))
                {
                    MessageBox.Show("Shipping Street must not be empty.");
                    return;
                }

                string shippingCity = ShippingCity.Text;
                if (string.IsNullOrWhiteSpace(shippingCity))
                {
                    MessageBox.Show("Shipping City must not be empty.");
                    return;
                }

                SqlCommand insertCommand = new SqlCommand("INSERT INTO ShippingDetails (ShippingID, OrderID, ShippingDate, ShippingStreet, ShippingCity) VALUES (@shippingId, @orderId, @shippingDate, @shippingStreet, @shippingCity)", dbConnection);

                insertCommand.Parameters.AddWithValue("@shippingId", shippingId);
                insertCommand.Parameters.AddWithValue("@orderId", orderId);
                insertCommand.Parameters.AddWithValue("@shippingDate", shippingDate);
                insertCommand.Parameters.AddWithValue("@shippingStreet", shippingStreet);
                insertCommand.Parameters.AddWithValue("@shippingCity", shippingCity);

                dbConnection.Open();
                insertCommand.ExecuteNonQuery();

                ShippingID.Clear();
                OrderID.Clear();
                ShippingDate.Clear();
                ShippingStreet.Clear();
                ShippingCity.Clear();

                ReloadShippingDetailsTableView();

                MessageBox.Show("Inserted successfully to the Database");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                dbConnection.Close();
            }
        }


        private void deleteModel_Click(object sender, EventArgs e)
        {
            try
            {
                if (!int.TryParse(ID.Text, out int shippingId))
                {
                    MessageBox.Show("Shipping ID must be an integer.");
                    return;
                }

                SqlCommand deleteCommand = new SqlCommand("DELETE FROM ShippingDetails WHERE ShippingID = @shippingId", dbConnection);

                deleteCommand.Parameters.Add("@shippingId", SqlDbType.Int).Value = shippingId;

                dbConnection.Open();
                int rowsAffected = deleteCommand.ExecuteNonQuery();
                dbConnection.Close();

                if (rowsAffected > 0)
                {
                    ReloadShippingDetailsTableView();
                    ID.Clear();
                    MessageBox.Show("Record deleted successfully.");
                }
                else
                {
                    MessageBox.Show("No record found with the specified Shipping ID.");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred while deleting the record: " + ex.Message);
            }
            finally
            {
                if (dbConnection.State == ConnectionState.Open)
                {
                    dbConnection.Close();
                }
            }
        }


        private void updateModel_Click(object sender, EventArgs e)
        {
            try {
            
                if (!int.TryParse(shippingIDTextBox.Text, out int shippingId))
                {
                    MessageBox.Show("Shipping ID must be an integer.");
                    return;
                }

                if (!int.TryParse(orderIDTextBox.Text, out int orderId))
                {
                    MessageBox.Show("Order ID must be an integer.");
                    return;
                }

                if (!DateTime.TryParse(shippingDateTextBox.Text, out DateTime shippingDate))
                {
                    MessageBox.Show("Invalid Shipping Date format.");
                    return;
                }

                string shippingStreet = shippingStreetTextBox.Text;
                if (string.IsNullOrWhiteSpace(shippingStreet))
                {
                    MessageBox.Show("Shipping Street must not be empty.");
                    return;
                }

                string shippingCity = shippingCityTextBox.Text;
                if (string.IsNullOrWhiteSpace(shippingCity))
                {
                    MessageBox.Show("Shipping City must not be empty.");
                    return;
                }

                SqlCommand updateCommand = new SqlCommand("UPDATE ShippingDetails SET ShippingDate = @shippingDate, ShippingStreet = @shippingStreet, ShippingCity = @shippingCity WHERE ShippingID = @shippingId", dbConnection);

                updateCommand.Parameters.AddWithValue("@shippingDate", shippingDate);
                updateCommand.Parameters.AddWithValue("@shippingStreet", shippingStreet);
                updateCommand.Parameters.AddWithValue("@shippingCity", shippingCity);
                updateCommand.Parameters.AddWithValue("@shippingId", shippingId);

                dbConnection.Open();
                int rowsAffected = updateCommand.ExecuteNonQuery();
                dbConnection.Close();

                if (rowsAffected > 0)
                {
                    ReloadShippingDetailsTableView();
                    ClearInputFields();
                    MessageBox.Show("Record updated successfully.");
                }
                else
                {
                    MessageBox.Show("No record found with the specified Shipping ID.");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred while updating the record: " + ex.Message);
            }
            finally
            {
                if (dbConnection.State == ConnectionState.Open)
                {
                    dbConnection.Close();
                }
            }


        }

        private void ClearInputFields()
        {
            shippingIDTextBox.Clear();
            orderIDTextBox.Clear();
            shippingDateTextBox.Clear();
            shippingStreetTextBox.Clear();
            shippingCityTextBox.Clear();
        }


        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load_1(object sender, EventArgs e)
        {

        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {


        }

        private void dataGridView1_CellContentClick_1(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void dataGridView1_CellContentClick_2(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }
    }
}
