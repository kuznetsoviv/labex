import { useState } from "react";
import { TextField, Button, Box } from "@mui/material";

function AddWishForm({ onAddWish }) {
    const [wish, setWish] = useState("");

    const handleSubmit = (event) => {
        event.preventDefault();
        onAddWish(wish);
        setWish("");
    };

    return (
        <Box
            component="form"
            onSubmit={handleSubmit}
            sx={{
                mt: 2,
                display: "flex",
                alignItems: "center",
                justifyContent: "center"
            }}
        >
            <TextField
                label="Your Wish"
                variant="outlined"
                value={wish}
                onChange={(e) => setWish(e.target.value)}
                sx={{ mr: 2 }}
            />
            <Button variant="contained" color="secondary" type="submit">
                Submit Wish
            </Button>
        </Box>
    );
}

export default AddWishForm;