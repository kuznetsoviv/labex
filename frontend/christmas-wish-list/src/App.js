import { useState } from "react";
import AddWishForm from "./components/AddWishForm";
import WishList from "./components/WishList";
import Snowflakes from "./components/Snowflakes";
import { Container, Button, Box } from "@mui/material";
import "./App.css";

function App() {
    const [wishes, setWishes] = useState([]);
    const [showForm, setShowForm] = useState(false);

    const handleAddWish = (newWish) => {
        setWishes([...wishes, newWish]);
        setShowForm(false);
    };

    const handleRemoveWish = (wish) => {
        setWishes(wishes.filter((item) => item !== wish));
    };

    return (
        <Container maxWidth="md" className="app-container">
            <Snowflakes />
            <Box sx={{ my: 4, textAlign: "center" }}>
                <Button
                    variant="contained"
                    color="primary"
                    onClick={() => setShowForm(!showForm)}
                >
                    {showForm ? "Close" : "Add Wish"}
                </Button>
                {showForm && <AddWishForm onAddWish={handleAddWish} />}
                <WishList wishes={wishes} onRemoveWish={handleRemoveWish} />
            </Box>
        </Container>
    );
}

export default App;