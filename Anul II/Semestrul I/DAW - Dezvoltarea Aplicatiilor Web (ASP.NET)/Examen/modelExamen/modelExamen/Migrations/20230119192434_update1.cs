using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace modelExamen.Migrations
{
    /// <inheritdoc />
    public partial class update1 : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateIndex(
                name: "IX_Giftcards_BrandId",
                table: "Giftcards",
                column: "BrandId");

            migrationBuilder.AddForeignKey(
                name: "FK_Giftcards_Brands_BrandId",
                table: "Giftcards",
                column: "BrandId",
                principalTable: "Brands",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Giftcards_Brands_BrandId",
                table: "Giftcards");

            migrationBuilder.DropIndex(
                name: "IX_Giftcards_BrandId",
                table: "Giftcards");
        }
    }
}
