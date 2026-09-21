import { Card, CardContent, Typography, IconButton } from "@mui/material";
import CloseIcon from "@mui/icons-material/Close";
import "./Postcard.css";

function Postcard({ wish, onRemoveWish }) {
    return (
        <Card className="postcard">
            <CardContent>
                <IconButton
                    className="delete-button"
                    onClick={() => onRemoveWish(wish)}
                    size="small"
                >
                    <CloseIcon fontSize="inherit" />
                </IconButton>
                <Typography variant="h6" component="div">
                    {wish}
                </Typography>
            </CardContent>
        </Card>
    );
}

export default Postcard;