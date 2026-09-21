import Postcard from "./Postcard";
import "./WishList.css";

function WishList({ wishes, onRemoveWish }) {
    return (
        <div className="wish-wall">
            {wishes.map((wish, index) => (
                <Postcard key={index} wish={wish} onRemoveWish={onRemoveWish} />
            ))}
        </div>
    );
}

export default WishList;